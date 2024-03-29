//
// Created by Marty Kostov on 18.07.22.
//

#ifndef LISTFUNC_PARSER_HPP
#define LISTFUNC_PARSER_HPP

#include "Lexer.hpp"
#include "FunctionRegister.hpp"

#include "Expressions/NumberExpression.hpp"
#include "Expressions/ListExpression.hpp"
#include "Functions/CustomFunction.hpp"
#include "Functions/FunctionProxy.hpp"
#include "Expressions/FunctionCallExpression.hpp"

///Transform a text to expressions
class Parser {
    Lexer *lexer;
    FunctionRegister *functionRegister;

    IExpression *getExpression(const Token& token);
    NumberExpression *getNegativeNumberExpression();
    FunctionCallExpression *getListExpression();
    IExpression *getExpressionWhitIdentifier(const std::string& identifier);
    NumberExpression *addFunc(const std::string& identifier);
    FunctionCallExpression *getFuncCallExpression(const std::string& identifier);
    static ParameterExpression* getParameterExpression(const Token& token);

    IExpression* getExpression();
public:
    explicit Parser();
    virtual ~Parser();

    ///add new text for executing
    void enterText(const std::string &inProgram);

    IExecutable* getExecutable();
};


#endif //LISTFUNC_PARSER_HPP
