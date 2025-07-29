//this program was made by anyone
//yes
#include <iostream>
#include <windows.h>

int main()
{
	HDC hdc = GetDC(NULL);

	int w = GetSystemMetrics(SM_CXSCREEN), h = GetSystemMetrics(SM_CYSCREEN);

	POINT points[3];
	std::string typegdi;

	std::cout << "bitblt, patblt, plgblt, or all?\n>>";
	std::cin >> typegdi;

	if (typegdi == "bitblt")
	{
		while (true)
		{
			BitBlt(hdc, rand() % 500, rand() % w + h, w, h, hdc, rand() % 1000, rand() % w - h, SRCCOPY);
		}
	}
	else if (typegdi == "patblt")
	{
		while (true)
		{
			PatBlt(hdc, rand() % 200, rand() % 500, w, h, PATINVERT);
		}
	}
	else if (typegdi == "plgblt")
	{
		int x = rand() % 1000, y = rand() % w * h;

		points[0].x = 0;
		points[0].y = 0;

		points[1].x = rand() % w;
		points[1].y = rand() % h;

		points[2].x = rand() % w + h;
		points[2].y = rand() % w - h;

		PlgBlt(hdc, points, x, y, w, h, rand() % 2838, rand() % 1 + NULL, 0, 0);
	}
	else if (typegdi == "all")
	{
		int x = rand() % 1000, y = rand() % w * h;

		points[0].x = 0;
		points[0].y = 0;

		points[1].x = rand() % w;
		points[1].y = rand() % h;

		points[2].x = rand() % w + h;
		points[2].y = rand() % w - h;

		PlgBlt(hdc, points, x, y, w, h, rand() % 2838, rand() % 1 + NULL, 0, 0);
		BitBlt(hdc, rand() % 500, rand() % w + h, w, h, hdc, rand() % 1000, rand() % w - h, SRCCOPY);
		PatBlt(hdc, rand() % 200, rand() % 500, w, h, PATINVERT);
	}
}