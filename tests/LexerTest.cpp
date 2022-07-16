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

    std::vector<Token>* tokensPtr = lexer->getTokens(inProgram);
    ASSERT_NE(tokensPtr, nullptr);

    std::vector<Token> &tokens = *tokensPtr;
    ASSERT_EQ(tokens.size(), 1);

    ASSERT_EQ(tokens[0].type, TokenType::NUMBER);
    ASSERT_EQ(tokens[0].value, "32");

    delete tokensPtr;
}

TEST_F(LexerTest, testList) {
    std::string inProgram = "[ 1 12 123 ]";

    std::vector<Token>* tokensPtr = lexer->getTokens(inProgram);
    ASSERT_NE(tokensPtr, nullptr);

    std::vector<Token> &tokens = *tokensPtr;
    ASSERT_EQ(tokens.size(), 5);

    ASSERT_EQ(tokens[0].type, TokenType::OPERATOR);
    ASSERT_EQ(tokens[0].value, "[");
    ASSERT_EQ(tokens[1].type, TokenType::NUMBER);
    ASSERT_EQ(tokens[1].value, "1");
    ASSERT_EQ(tokens[2].type, TokenType::NUMBER);
    ASSERT_EQ(tokens[2].value, "12");
    ASSERT_EQ(tokens[3].type, TokenType::NUMBER);
    ASSERT_EQ(tokens[3].value, "123");
    ASSERT_EQ(tokens[4].type, TokenType::OPERATOR);
    ASSERT_EQ(tokens[4].value, "]");

    delete tokensPtr;
}

TEST_F(LexerTest, testFunctionDeclaration) {
    std::string inProgram = "myList -> [ #0 #1 #2 ]";

    std::vector<Token>* tokensPtr = lexer->getTokens(inProgram);
    ASSERT_NE(tokensPtr, nullptr);

    std::vector<Token> &tokens = *tokensPtr;
    ASSERT_EQ(tokens.size(), 7);

    ASSERT_EQ(tokens[0].type, TokenType::IDENTIFIER);
    ASSERT_EQ(tokens[0].value, "myList");
    ASSERT_EQ(tokens[1].type, TokenType::OPERATOR);
    ASSERT_EQ(tokens[1].value, "->");
    ASSERT_EQ(tokens[2].type, TokenType::OPERATOR);
    ASSERT_EQ(tokens[2].value, "[");
    ASSERT_EQ(tokens[3].type, TokenType::ARGUMENT);
    ASSERT_EQ(tokens[3].value, "#0");
    ASSERT_EQ(tokens[4].type, TokenType::ARGUMENT);
    ASSERT_EQ(tokens[4].value, "#1");
    ASSERT_EQ(tokens[5].type, TokenType::ARGUMENT);
    ASSERT_EQ(tokens[5].value, "#2");
    ASSERT_EQ(tokens[6].type, TokenType::OPERATOR);
    ASSERT_EQ(tokens[6].value, "]");

    delete tokensPtr;
}