//
// Created by Marty Kostov on 18.07.22.
//

#include "Parser.hpp"

IExpression *Parser::getExpression() {
    Token token = lexer->getNextToken();
    return getExpression(token);
}

IExpression *Parser::getExpression(const Token& token) {
    switch (token.type) {
        case TokenType::END:
            return nullptr;

        case TokenType::OPERATOR:
            if (token.value == "[") {
                return getListExpression();

            } else if (token.value == "-") {
                return getNegativeNumberExpression();

            } else {
                throw std::invalid_argument("Unexpected operator '" + token.value + "'!");
            }

        case TokenType::NUMBER:
            return new NumberExpression( std::stod( token.value ) );

        case TokenType::ARGUMENT:
            return getParameterExpression(token);

        case TokenType::IDENTIFIER:
            return getExpressionWhitIdentifier(token.value);
            
        case TokenType::ERROR:
            throw std::invalid_argument(token.value);
    }
}

ListExpression *Parser::getListExpression() {
    bool isListExecutable = true;
    std::vector<IExpression *> items;
    Token token = lexer->getNextToken();
    try {
        while (token.value != "]") {
            if (token.type == TokenType::ARGUMENT){
                isListExecutable = false;
            }
            IExpression *item = getExpression(token);
            if (!item) {
                throw std::invalid_argument("Missing operator ']'!");
            }
            items.push_back(item);
            token = lexer->getNextToken();
        }

    } catch (const std::invalid_argument& ia) {
        for (int i = 0; i < items.size(); ++i) {
            delete items[i];
        }
        throw ia;
    }

    if (isListExecutable) {
        auto list = new ExecutableListExpression(nullptr, nullptr);
        for (size_t i = items.size(); i > 0; --i) {
            list = new ExecutableListExpression(items[i-1], list);
        }
        return list;
    }

    auto list = new ListExpression(nullptr, nullptr);
    for (size_t i = items.size(); i > 0; --i) {
        list = new ListExpression(items[i-1], list);
    }
    return list;
}

IExpression *Parser::getExpressionWhitIdentifier(const std::string& identifier) {
    Token token = lexer->getNextToken();

    if (token.type == TokenType::OPERATOR) {
        if (token.value == "(") {
            return getFuncCallExpression(identifier);

        } else if (token.value == "->") {
            return addFunc(identifier);

        } else {
            throw std::invalid_argument("Unexpected operator '" + token.value + "'!");
        }

    } else {
        throw std::invalid_argument("Unexpected word '" + token.value + "'!");
    }
}

NumberExpression *Parser::addFunc(const std::string& identifier) {
    IExpression *expression = getExpression();
    if (!expression) {
        throw std::invalid_argument("Missing expression after '->'!");
    }

    auto *function = new CustomFunction(expression);

    bool isReplacesDeclaration = functionRegister->add(identifier, function->getParmCount(), function);

    return new NumberExpression(isReplacesDeclaration);
}


FunctionCallExpression *Parser::getFuncCallExpression(const std::string& identifier) {

    std::vector<IExpression *> arguments;

    Token token = lexer->getNextToken();
    auto* func = new FunctionProxy(functionRegister, identifier);

    try {
        while (token.value != ")") {
            IExpression *arg = getExpression(token);
            if (!arg) {
                throw std::invalid_argument("Missing operator ')'");
            }
            arguments.push_back(arg);
            token = lexer->getNextToken();

            if (token.type == TokenType::OPERATOR) {
                if (token.value == ",") {
                    token = lexer->getNextToken();
                    continue;
                } else if (token.value == ")") {
                    break;
                }
            }

            throw std::invalid_argument("Missing operator ','!");
        }
        func->addArgsNum(arguments.size());
//        func = functionRegister->get(identifier, arguments.size());

//        if (!func) {
//            throw std::invalid_argument("Unknown function '" + identifier + "'!");
//        }

    } catch (const std::invalid_argument& ia) {
        for (int i = 0; i < arguments.size(); ++i) {
            delete arguments[i];
        }
        throw ia;
    }

    auto* functionCall = new FunctionCallExpression(func, arguments);
    return functionCall;
}

ParameterExpression *Parser::getParameterExpression(const Token &token) {
    assert(token.type == TokenType::ARGUMENT);
    size_t index = std::stoull(token.value);

    return new ParameterExpression(index);
}

Parser::Parser() {
    this->lexer = new Lexer();
    functionRegister = new FunctionRegister();
}
Parser::~Parser() {
    delete lexer;
    delete functionRegister;
}

NumberExpression *Parser::getNegativeNumberExpression() {
    Token token = lexer->getNextToken();
    if (token.type != TokenType::NUMBER) {
        throw std::invalid_argument("Unexpected operator '-'!");
    }


    return new NumberExpression( -std::stod( token.value ) );
}

void Parser::enterText(const std::string &inProgram) {
    lexer->enterText(inProgram);
}

IExecutable *Parser::getExecutable() {
    IExpression *expression = getExpression();
    auto *executable = dynamic_cast<IExecutable *>(expression);

    IExpression *nextExpression = getExpression();

    if (nextExpression) {
        delete expression;
        delete nextExpression;
        throw std::invalid_argument("Not executable expression!");
    }

    if (!expression || executable) {
        return executable;
    } else {
        throw std::invalid_argument("Not executable expression!");
    }
}

