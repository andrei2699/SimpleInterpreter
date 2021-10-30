add_library(Parser
    src/Tokens/TokenType.hpp
    src/Tokens/IToken.cpp
    src/Tokens/IToken.hpp
    src/Tokens/NumericLiteralToken.cpp
    src/Tokens/NumericLiteralToken.hpp
    src/Tokens/OperatorToken.cpp
    src/Tokens/OperatorToken.hpp

    src/Lexer.cpp
    src/Lexer.hpp

    src/AST.cpp
    src/AST.hpp

    src/Parser.cpp
    src/Parser.hpp
)

target_link_libraries(Parser PRIVATE List)

target_include_directories(Parser PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
