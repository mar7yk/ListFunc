//
// Created by Marty Kostov on 20.07.22.
//

#include <gtest/gtest.h>
#include "../src/Parser.hpp"

struct ParserTest : testing::Test {
    Parser *parser;

    ParserTest() {
        parser = new Parser();
    }

    ~ParserTest() override {
        delete this->parser;
    }

    void test( const std::vector<std::string> &inProgram, const std::vector<std::string> &results) {

        ASSERT_EQ(inProgram.size(), results.size());

        for (int i = 0; i < inProgram.size(); ++i) {
            parser->enterText(inProgram[i]);
            IExecutable* expression = parser->getExecutable();
            std::string result = expression->execute();
            delete expression;
            ASSERT_EQ(result, results[i]);
        }


    }
};


TEST_F(ParserTest, testNumber) {
    std::vector<std::string> inProgram = {"123"};
    std::vector<std::string> results = {"123"};

    this->test(inProgram, results);
}

TEST_F(ParserTest, testList) {
    std::vector<std::string> inProgram = {"[1 1.2111119 123]"};
    std::vector<std::string> results = {"[1 1.211112 123]"};

    this->test(inProgram, results);
}

TEST_F(ParserTest, testDeclrFunc) {
    std::vector<std::string> inProgram = { "a -> [#0 #1 #0]", "a([1 2], 3)"};
    std::vector<std::string> results = {"0", "[[1 2] 3 [1 2]]"};

    this->test(inProgram, results);
}

TEST_F(ParserTest, testEq) {
    std::vector<std::string> inProgram = {
            "eq(1,1)",
            "eq(1,1.1)",
            "eq(1,[1])",
            "eq([1 2 3],[[1 2 3]])",
    };
    std::vector<std::string> results = {"1", "0", "1", "1"};

    this->test(inProgram, results);
}

TEST_F(ParserTest, testLe) {
    std::vector<std::string> inProgram = {
            "le(1,1)",
            "le(1,1.1)",
            "le(5,1)",
    };
    std::vector<std::string> results = {"0", "1", "0"};

    this->test(inProgram, results);
}

TEST_F(ParserTest, testNand) {
    std::vector<std::string> inProgram = {
            "nand(5,1)",
            "nand(0,346)",
            "nand(346,0)",
    };
    std::vector<std::string> results = {"0", "1", "1"};

    this->test(inProgram, results);
}

TEST_F(ParserTest, testLength) {
    std::vector<std::string> inProgram = {
            "length(5)",
            "length([1 0 [23 3] 43])",
    };
    std::vector<std::string> results = {"-1", "4"};

    this->test(inProgram, results);
}

TEST_F(ParserTest, testHead) {
    std::vector<std::string> inProgram = {
            "head([5 21 24])",
            "head([[23 3] 43])",
    };
    std::vector<std::string> results = {"5", "[23 3]"};

    this->test(inProgram, results);
}

TEST_F(ParserTest, testTail) {
    std::vector<std::string> inProgram = {
            "tail([5 21 24])",
            "tail([1 0 [23 3] 43])",
    };
    std::vector<std::string> results = {"[21 24]", "[0 [23 3] 43]"};

    this->test(inProgram, results);
}

TEST_F(ParserTest, testList0) {
    std::vector<std::string> inProgram = {
            "list(5)",
            "list(-5)",
            "list(0.25)",
    };
    std::vector<std::string> results = {
            "[5 6 7 8 9 10 11 12 ...]",
            "[-5 -4 -3 -2 -1 0 1 2 ...]",
            "[0.250000 1.250000 2.250000 3.250000 4.250000 5.250000 6.250000 7.250000 ...]",
    };

    this->test(inProgram, results);
}

TEST_F(ParserTest, testList1) {
    std::vector<std::string> inProgram = {
            "list(5, 3)",
            "list(-5, 10)",
            "list(0.25, 0.125)\n",
    };
    std::vector<std::string> results = {
            "[5 8 11 14 17 20 23 26 ...]",
            "[-5 5 15 25 35 45 55 65 ...]",
            "[0.250000 0.375000 0.500000 0.625000 0.750000 0.875000 1 1.125000 ...]",
    };

    this->test(inProgram, results);
}

TEST_F(ParserTest, testList2) {
    std::vector<std::string> inProgram = {
            "list(5, 3, 3)",
            "list(-5, 10, 4)",
            "list(0.25, 0.125, 7)",
    };
    std::vector<std::string> results = {
            "[5 8 11]",
            "[-5 5 15 25]",
            "[0.250000 0.375000 0.500000 0.625000 0.750000 0.875000 1]",
    };

    this->test(inProgram, results);
}

TEST_F(ParserTest, testConcat) {
    std::vector<std::string> inProgram = {
            "concat([5 3], [3 5])",
            "concat([5 [8 4] 3], [[3 7] 0 4])",
    };
    std::vector<std::string> results = {
            "[5 3 3 5]",
            "[5 [8 4] 3 [3 7] 0 4]",
    };

    this->test(inProgram, results);
}

TEST_F(ParserTest, testIf) {
    std::vector<std::string> inProgram = {
            "if(24, 20, 200)",
            "if(0, 20, 200)",
    };
    std::vector<std::string> results = {"20", "200"};

    this->test(inProgram, results);
}

TEST_F(ParserTest, testAritmetic) {
    std::vector<std::string> inProgram = {
            "sqrt( div( sub( mul( add(3,2), 2), 6), 2 ) )",
            "mod(14, 5)",
    };
    std::vector<std::string> results = {"4", "4"};

    this->test(inProgram, results);
}

