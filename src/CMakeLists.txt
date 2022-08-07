project(ListFunc_src)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        Engine.cpp Engine.hpp
        Lexer.cpp Lexer.hpp
        Token.hpp
        Parser.cpp Parser.hpp
        Expressions/IExpression.hpp
        Expressions/NumberExpression.cpp Expressions/NumberExpression.hpp
        Expressions/ListExpression.cpp Expressions/ListExpression.hpp
        Expressions/InfinityListExpression.cpp Expressions/InfinityListExpression.hpp
        Expressions/ParameterExpression.cpp Expressions/ParameterExpression.hpp
        Functions/IFunction.hpp
        Functions/CustomFunction.cpp Functions/CustomFunction.hpp
        Expressions/FunctionCallExpression.cpp Expressions/FunctionCallExpression.hpp
        FunctionRegister.cpp FunctionRegister.hpp
        Functions/EqFunction.cpp Functions/EqFunction.hpp
        Functions/LeFunction.cpp Functions/LeFunction.hpp
        Functions/NandFunction.cpp Functions/NandFunction.hpp
        Functions/LengthFunction.cpp Functions/LengthFunction.hpp
        Functions/HeadFunction.cpp Functions/HeadFunction.hpp
        Functions/TailFunction.cpp Functions/TailFunction.hpp
        Functions/ListZeroFunction.cpp Functions/ListZeroFunction.hpp
        Functions/ListOneFunction.cpp Functions/ListOneFunction.hpp
        Functions/ListTwoFunction.cpp Functions/ListTwoFunction.hpp
        Functions/ConcatFunction.cpp Functions/ConcatFunction.hpp
        Functions/IfFunction.cpp Functions/IfFunction.hpp
        Functions/ReadFunction.cpp Functions/ReadFunction.hpp
        Functions/IntFunction.cpp Functions/IntFunction.hpp
        Functions/AddFunction.cpp Functions/AddFunction.hpp
        Functions/SubFunction.cpp Functions/SubFunction.hpp
        Functions/MulFunction.cpp Functions/MulFunction.hpp
        Functions/TwoNumberFunction.cpp Functions/TwoNumberFunction.hpp
        Functions/DivFunction.cpp Functions/DivFunction.hpp
        Functions/ModFunction.cpp Functions/ModFunction.hpp
        Functions/SqrtFunction.cpp Functions/SqrtFunction.hpp
        Functions/WriteFunction.cpp Functions/WriteFunction.hpp
        ConsoleHandler.cpp ConsoleHandler.hpp
        MemoryManager.cpp MemoryManager.hpp
        Functions/FunctionProxy.cpp Functions/FunctionProxy.hpp Functions/GetListFunction.cpp Functions/GetListFunction.hpp Expressions/ExecutableExpression.hpp FileHandler.cpp FileHandler.hpp)

add_library(src STATIC ${SOURCE_FILES})