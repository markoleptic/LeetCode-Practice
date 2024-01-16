#include <cassert>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class VoxelArray
{
public:
	const unsigned int mSizeX{0};
	const unsigned int mSizeY{0};
	const unsigned int mSizeZ{0};

	VoxelArray(unsigned int sizeX, unsigned int sizeY, unsigned int sizeZ)
		: mSizeX(sizeX), mSizeY(sizeY), mSizeZ(sizeZ), mVoxels(mSizeX * mSizeY * mSizeZ, 0)
	{
	}

	int getValueAt(unsigned int x, unsigned int y, unsigned int z)
	{
		int index = x + mSizeY * y + mSizeZ * mSizeY * z;
		return mVoxels[index];
	}

	void setValueAt(unsigned int x, unsigned int y, unsigned int z, int value)
	{
		int index = x + mSizeY * y + mSizeZ * mSizeY * z;
		mVoxels[index] = value;
		if (entangleMap.contains(index))
		{
			mVoxels[entangleMap[index]] = value;
		}
	}

	void entangle(unsigned int x, unsigned int y, unsigned int z, unsigned int x2, unsigned int y2, unsigned int z2)
	{
		int index1 = x + mSizeY * y + mSizeZ * mSizeY * z;
		int index2 = x2 + mSizeY * y2 + mSizeZ * mSizeY * z2;
		entangleMap[index1] = index2;
		entangleMap[index2] = index1;
	}

private:
	vector<int> mVoxels;
	map<int, int> entangleMap;
};

void testSetGetAux(VoxelArray &voxels, unsigned int x, unsigned int y, unsigned int z)
{
	voxels.setValueAt(x, y, z, 32);
	assert(voxels.getValueAt(x, y, z) == 32);
}

void testSetGet()
{
	VoxelArray voxels(10, 10, 10);
	testSetGetAux(voxels, 9, 9, 9);
	testSetGetAux(voxels, 0, 0, 0);
	testSetGetAux(voxels, 0, 9, 0);
}

void testEntanglement()
{
	VoxelArray voxels(10, 10, 10);
	voxels.entangle(1, 1, 1, 3, 3, 3);
	voxels.setValueAt(1, 1, 1, 42);
	assert(voxels.getValueAt(3, 3, 3) == 42);
	voxels.setValueAt(3, 3, 3, 18);
	assert(voxels.getValueAt(1, 1, 1) == 18);
}

int main()
{
	testSetGet();
	testEntanglement();
	cout << "Tests finished\n";
	return 0;
}