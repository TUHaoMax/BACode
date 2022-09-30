


include_directories(C:/Users/htu/AppData/Local/Programs/Python/Python310/include)
link_libraries(C:/Users/htu/AppData/Local/Programs/Python/Python310/libs/python310.lib)
add_executable(chessExec
        main.cpp)
target_include_directories(chessExec PUBLIC
../lib/chessAI )

target_link_libraries(chessExec chessAI)