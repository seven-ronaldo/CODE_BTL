#include "Texture.h"
#include "Buttons.h"
#include "Variables.h"
#include "constant.h"
#include "function.h"
using namespace std;


int main(int argc, char* argv[])
{
	LFunction game;
	//Start up SDL and create window: Khởi động SDL và tạo cửa sổ
	if (!game.init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		if (game.loadmedia())
		{
			if (game.loadMenuMedia())
			{
				game.showMenu();
				while (mainLoop)
				{
					if (isChoosing)
					{
						game.showModeChoice();
					}
					if (customMode) game.CustomMode();
					while (isRunning)
					{
						game.handleEvent();
						game.setButtonPosition();
						game.renderGame();
					}
				}
			}
		}
	}
	//Free resources and close SDL: giải phóng tài nguyên và đóng SDL
	game.close();
	return 0;
}



