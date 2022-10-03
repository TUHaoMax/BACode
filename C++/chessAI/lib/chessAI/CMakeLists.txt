

include_directories(C:/Users/htu/AppData/Local/Programs/Python/Python310/include)
link_libraries(C:/Users/htu/AppData/Local/Programs/Python/Python310/libs/python310.lib)
add_library(chessAI
        ChessGame.cpp
        ChessGame.h
        HumanChessPlayer.cpp
        ChessAI.cpp
        Evaluation.cpp
        Evaluation.h
        thread_pool.cc
        MoveSorter.cpp
        MoveSorter.h
        Opening.cpp
        Opening.h
        OnLineOP.cpp
        OnLineOP.h
        )
target_include_directories(chessAI PUBLIC ../thc/src)

target_link_libraries(chessAI
        thc_chess_static
        ${CMAKE_THREAD_LIBS_INIT})