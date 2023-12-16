#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

static void fillColor(vector<vector<int>> &image, int sr, int sc, int color, int originalColor)
{
	if (sr < 0 || sr >= static_cast<int>(image.size()))
	{
		return;
	}
	if (sc < 0 || sc >= static_cast<int>(image[sr].size()))
	{
		return;
	}
	if (image[sr][sc] != originalColor)
	{
		return;
	}
	if (image[sr][sc] == color)
	{
		return;
	}

	image[sr][sc] = color;

	fillColor(image, sr + 1, sc, color, originalColor);
	fillColor(image, sr, sc + 1, color, originalColor);
	fillColor(image, sr - 1, sc, color, originalColor);
	fillColor(image, sr, sc - 1, color, originalColor);
}

/**
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the
pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of
the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same
color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.
*/
class Solution
{
      public:
	vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
	{
		cout << sr << sc << color << endl;

		fillColor(image, sr, sc, color, image[sr][sc]);
		return image;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::floodFill);
}
#endif