#include <bits/stdc++.h>

using namespace std;

void pageFault(int frame_size, int *ref, int len)
{
	// To dynamically allocate an array,
	// it represents the page frames.
	int *arr = new int[frame_size];

	// To initialize the array
	for (int i = 0; i < frame_size; i++)
	{
		arr[i] = -1;
	}

	// To count page faults
	int cnt = 0;
	int start = 0;
	int flag;
	int elm;

	for (int i = 0; i < len; i++)
	{
		elm = ref[i];
		// Linear search to find if the page exists
		flag = 0;
		for (int j = 0; j < frame_size; j++)
		{
			if (elm == arr[j])
			{
				flag = 1;
				break;
			}
		}
		// If the page doesn't exist it is inserted,
		// count is incremented
		if (flag == 0)
		{
			if (start < frame_size)
			{
				arr[start] = elm;
				start++;
			}
			else if (start == frame_size)
			{
				arr[0] = elm;
				start = 1;
			}
			cnt++;
		}
	}
	cout << "When the number of frames are: " << frame_size << ", ";
	cout << "the number of page faults is : " << cnt << endl;
}

int main()
{
	// Reference array
	int ref[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
	int len = sizeof(ref) / sizeof(ref[0]);
	// The frame size
	int frame_size = 4;

	pageFault(frame_size, ref, len);

	// Increase value of frame size
	frame_size = 5;

	// The page fault increases
	// even after increasing the
	// the number of frames.
	// This is Belady's Anomaly
	pageFault(frame_size, ref, len);
}
