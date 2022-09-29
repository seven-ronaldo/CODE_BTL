#include "Texture.h"
#include "Buttons.h"
#include "Variables.h"
#include "constant.h"
#include "function.h"
using namespace std;


int main(int argc, char* argv[])
{
	//Start up SDL and create window: Khởi động SDL và tạo cửa sổ
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		if (loadmedia())
		{
			if (loadMenuMedia())
			{
				showMenu();
				while (mainLoop)
				{
					if (isChoosing)
					{
						showModeChoice();
					}
					if (customMode) CustomMode();
					while (isRunning)
					{
						handleEvent();
						setButtonPosition();
						renderGame();
					}
				}
			}
		}
	}
	//Free resources and close SDL: giải phóng tài nguyên và đóng SDL
	close();
	return 0;
}



