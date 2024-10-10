#include <raylib.h>
#include <kos.h>
#include "game/game.h"
#include "constants/constants.h"
#include "colors/colors.h"
#include "system/cd.h"
#include <iostream>

#include <kos/init.h>
#include <kos/dbgio.h>
#include <dc/sound/stream.h>
#include <adx/adx.h> 
#include <adx/snddrv.h> 

double lastUpdateTime = 0;

bool EventTriggered(double interval){
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval){
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}


// Find a better way to do this
void setVolume(){
    while( snddrv.drv_status != SNDDRV_STATUS_STREAMING ){
        thd_pass(); 
    }
    for (int i = 0; i < 8; i++){
        snddrv_volume_down();
    }
}

KOS_INIT_FLAGS(INIT_DEFAULT);
cd cdManager = cd();

int main(){
    const int screenWidth = 640;
    const int screenHeight = 480;

    InitWindow(screenWidth, screenHeight, "Tetris in KOS!");
    SetTargetFPS(60);

    // TODO: Come back to this and learn to load a font and use DrawTextEx
    // Font font = LoadFontEx("/rd/font.ttf", 64, 0, 0);

     /* Start the ADX stream, with looping enabled */
    
    if( adx_dec( "/rd/assets/sound/output.adx", 1 ) < 1 ){
        printf("Invalid ADX file\n");
    } else {
        while( snddrv.drv_status == SNDDRV_STATUS_NULL ){
            thd_pass(); 
        }
        setVolume();
    }


    Game game = Game();

    int TextUIDistance = Constants::gridWidthWithOffset + UIPadding::large;
    int scorePaddingHeight = UIPadding::medium;
    int scoreBoxPaddingHeight = scorePaddingHeight + 15 + UIPadding::small;
    int nextPaddingHeight = scoreBoxPaddingHeight + 60 + UIPadding::large;
    int nextBoxPaddingHeight = nextPaddingHeight + UIFont::medium + UIPadding::small;
    int gameOverPaddingHeight = nextBoxPaddingHeight + 180 + UIPadding::large;

    while(1){
        game.HandleInput();
        if(EventTriggered(0.2)){
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        DrawText("Hold", Constants::gridOffset - UIPadding::medium * 4, nextPaddingHeight, UIFont::medium, WHITE);
        DrawRectangleRounded({UIPadding::medium, (float)nextBoxPaddingHeight, Constants::gridOffset - UIPadding::large, 170}, 0.3, 6, lightBlue);

        DrawText("Score", TextUIDistance, scorePaddingHeight, UIFont::medium, WHITE);
        DrawRectangleRounded({Constants::gridWidthWithOffset + UIPadding::medium, (float)scoreBoxPaddingHeight, 170, 60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(GetFontDefault(), scoreText, UIFont::medium, 0);

        DrawText(scoreText, TextUIDistance + (170 - textSize.x)/2, scoreBoxPaddingHeight + UIPadding::medium, UIFont::medium, WHITE);

        DrawText("Next", TextUIDistance,  nextPaddingHeight, UIFont::medium, WHITE);
        DrawRectangleRounded({Constants::gridWidthWithOffset + UIPadding::medium, (float)nextBoxPaddingHeight, 170, 180}, 0.3, 6, lightBlue);
        if(game.gameOver){
            DrawText("GAME OVER\nPress start!", TextUIDistance, gameOverPaddingHeight, UIFont::medium, WHITE);
        }
        game.DrawNext(TextUIDistance - 20, nextBoxPaddingHeight + UIPadding::large * 1.5);
        
        game.DrawHeld(-20, nextBoxPaddingHeight + UIPadding::large * 1.5);
        EndDrawing();
        if(!cdManager.checkStatus()){
            break;
        }
    }

    printf("Finishing - Cleaning up\n");
    adx_stop();
    snd_stream_shutdown();
    printf("Finished - Cleaning up\n");

    cdManager.returnToBios();
    return 0;
}