//
// Created by Marty Kostov on 20.07.22.
//

#include <gtest/gtest.h>
#include "../src/Parser.hpp"

struct ParserTest : testing::Test {
    Lexer *lexer;
    Parser *parser;

    ParserTest() {
        lexer = new Lexer();
        parser = new Parser(lexer);
    }

    ~ParserTest() override {
        delete this->parser;
        delete this->lexer;
    }

    void test(const std::string &inProgram, const std::vector<std::string> &results) {
        size_t counter = 0;

        lexer->enterText(inProgram);

        IExecutable* expression = parser->getExecutable();
        while (expression) {
            std::string result = expression->execute();
            ASSERT_EQ(result, results[counter]);
            delete expression;
            expression = parser->getExecutable();
            ++counter;
        }

        ASSERT_EQ(counter, results.size());
    }
};


TEST_F(ParserTest, testNumber) {
    std::string inProgram = "123";
    std::vector<std::string> results = {"123"};

    this->test(inProgram, results);
}

TEST_F(ParserTest, testList) {
    std::string inProgram = "[1 1.2111119 123]";
    std::vector<std::string> results = {"[1 1.211112 123]"};

    this->test(inProgram, results);
}

TEST_F(ParserTest, testDeclrFunc) {
    std::string inProgram = "a -> [#0 #1 #0]\n"
                            "a([1 2], 3)";
    std::vector<std::string> results = {"0", "[[1 2] 3 [1 2]]"};

    this->test(inProgram, results);
}

TEST_F(ParserTest, testEq) {
    std::string inProgram = "eq(1,1)\n"
                            "eq(1,1.1)\n"
                            "eq(1,[1])\n"
                            "eq([1 2 3],[[1 2 3]])\n";
    std::vector<std::string> results = {"1", "0", "1", "1"};

    this->test(inProgram, results);
}

TEST_F(ParserTest, testLe) {
    std::string inProgram = "le(1,1)\n"
                            "le(1,1.1)\n"
                            "le(5,1)\n";
    std::vector<std::string> results = {"0", "1", "0"};

    this->test(inProgram, results);
}

TEST_F(ParserTest, testNand) {
    std::string inProgram = "nand(5,1)\n"
                            "nand(0,346)\n"
                            "nand(346,0)\n";
    std::vector<std::string> results = {"0", "1", "1"};

    this->test(inProgram, results);
}

TEST_F(ParserTest, testLength) {
    std::string inProgram = "length(5)\n"
                            "length([1 0 [23 3] 43])\n";
    std::vector<std::string> results = {"-1", "4"};

    this->test(inProgram, results);
}

TEST_F(ParserTest, testHead) {
    std::string inProgram = "head([5 21 24])\n"
                            "head([[23 3] 43])\n";
    std::vector<std::string> results = {"5", "[23 3]"};

    this->test(inProgram, results);
}

TEST_F(ParserTest, testTail) {
    std::string inProgram = "tail([5 21 24])\n"
                            "tail([1 0 [23 3] 43])\n";
    std::vector<std::string> results = {"[21 24]", "[0 [23 3] 43]"};

    this->test(inProgram, results);
}

TEST_F(ParserTest, testList0) {
    std::string inProgram = "list(5)\n"
                            "list(-5)\n"
                            "list(0.25)\n";
    std::vector<std::string> results = {
            "[5 6 7 8 9 10 11 12 ...]",
            "[-5 -4 -3 -2 -1 0 1 2 ...]",
            "[0.250000 1.250000 2.250000 3.250000 4.250000 5.250000 6.250000 7.250000 ...]",
    };

    this->test(inProgram, results);
}

TEST_F(ParserTest, testList1) {
    std::string inProgram = "list(5, 3)\n"
                            "list(-5, 10)\n"
                            "list(0.25, 0,125)\n";
    std::vector<std::string> results = {
            "[5 8 11 14 17 20 23 26 ...]",
            "[-5 5 15 25 35 45 55 55 ...]",
            "[0.250000 0.375000 0.500000 0.625000 0.750000 5.875000 1 1.125000 ...]",
    };

    this->test(inProgram, results);
}

TEST_F(ParserTest, testList2) {
    std::string inProgram = "list(5, 3, 3)\n"
                            "list(-5, 10, 4)\n"
                            "list(0.25, 0,125, 7)\n";
    std::vector<std::string> results = {
            "[5 8 11]",
            "[-5 5 15 25]",
            "[0.250000 0.375000 0.500000 0.625000 0.750000 5.875000 1]",
    };

    this->test(inProgram, results);
}

TEST_F(ParserTest, testConcat) {
    std::string inProgram = "concat([5 3], [3 5])\n"
                            "concat([5 [8 4] 3], [[3 7] 0 4])\n";
    std::vector<std::string> results = {
            "[5 3 3 5]",
            "[5 [8 4] 3 [3 7] 0 4]",
    };

    this->test(inProgram, results);
}

TEST_F(ParserTest, testIf) {
    std::string inProgram = "if(24, 20, 200)\n"
                            "if(0, 20, 200)\n";
    std::vector<std::string> results = {"20", "200"};

    this->test(inProgram, results);
}

TEST_F(ParserTest, testAritmetic) {
    std::string inProgram = "sqrt( div( sub( mul( add(3,2), 2), 6), 2 ) )\n"
                            "mod(14, 5)\n";
    std::vector<std::string> results = {"4", "4"};

    this->test(inProgram, results);
}

