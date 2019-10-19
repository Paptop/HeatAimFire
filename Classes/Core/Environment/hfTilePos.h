#pragma once


namespace Haf
{
	struct STilePos
	{
		int x, y;

		STilePos(int xx, int yy)
		: x(xx)
		, y(yy)
		{
		}

		STilePos()
		: x(0)
		, y(0)
		{
		}
	};
}