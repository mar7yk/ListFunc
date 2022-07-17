//
// Created by Marty Kostov on 15.07.22.
//

#include <gtest/gtest.h>
#include "../src/Lexer.hpp"

struct LexerTest : testing::Test {
    Lexer *lexer;
    LexerTest() {
        lexer = new Lexer();
    }

    ~LexerTest() override {
        delete this->lexer;
    }
};

TEST_F(LexerTest, testNumber) {
    std::string inProgram = "32";

    lexer->enterText(inProgram);

    Token token = lexer->getNextToken();
    ASSERT_EQ(token.type, TokenType::NUMBER);
    ASSERT_EQ(token.value, "32");

    token = lexer->getNextToken();
    ASSERT_EQ(token.type, TokenType::END);
}

TEST_F(LexerTest, testList) {
    std::string inProgram = "[ 1 1.2 123 ]";

    lexer->enterText(inProgram);

    Token token = lexer->getNextToken();
    ASSERT_EQ(token.type, TokenType::OPERATOR);
    ASSERT_EQ(token.value, "[");

    token = lexer->getNextToken();
    ASSERT_EQ(token.type, TokenType::NUMBER);
    ASSERT_EQ(token.value, "1");

    token = lexer->getNextToken();
    ASSERT_EQ(token.type, TokenType::NUMBER);
    ASSERT_EQ(token.value, "1.2");

    token = lexer->getNextToken();
    ASSERT_EQ(token.type, TokenType::NUMBER);
    ASSERT_EQ(token.value, "123");

    token = lexer->getNextToken();
    ASSERT_EQ(token.type, TokenType::OPERATOR);
    ASSERT_EQ(token.value, "]");

    token = lexer->getNextToken();
    ASSERT_EQ(token.type, TokenType::END);
}

TEST_F(LexerTest, testFunctionDeclaration) {
    std::string inProgram = "myList -> [#0 #1 #2]";

    lexer->enterText(inProgram);


    Token token = lexer->getNextToken();
    ASSERT_EQ(token.type, TokenType::IDENTIFIER);
    ASSERT_EQ(token.value, "myList");

    token = lexer->getNextToken();
    ASSERT_EQ(token.type, TokenType::OPERATOR);
    ASSERT_EQ(token.value, "->");

    token = lexer->getNextToken();
    ASSERT_EQ(token.type, TokenType::OPERATOR);
    ASSERT_EQ(token.value, "[");

    token = lexer->getNextToken();
    ASSERT_EQ(token.type, TokenType::ARGUMENT);
    ASSERT_EQ(token.value, "0");

    token = lexer->getNextToken();
    ASSERT_EQ(token.type, TokenType::ARGUMENT);
    ASSERT_EQ(token.value, "1");

    token = lexer->getNextToken();
    ASSERT_EQ(token.type, TokenType::ARGUMENT);
    ASSERT_EQ(token.value, "2");

    token = lexer->getNextToken();
    ASSERT_EQ(token.type, TokenType::OPERATOR);
    ASSERT_EQ(token.value, "]");

    token = lexer->getNextToken();
    ASSERT_EQ(token.type, TokenType::END);
}