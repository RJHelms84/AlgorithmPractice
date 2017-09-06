#include <iostream>
#include <string>

void InsertionSort(int* nums, int length)
{
	int j, temp;

	for (int i = 0; i < length; i++)
	{
		j = i;

		while (j > 0 && nums[j] < nums[j-1])
		{
			temp = nums[j];
			nums[j] = nums[j-1];
			nums[j-1] = temp;
			j--;
		}
	}
}

void SelectionSort(int* nums, int length)
{
	int temp, min;

	for (int i = 0; i < length - 1; i++)
	{
		min = i;

		for (int j = i + 1; j < length; j++) 
		{
			if (nums[j] < nums[min])
			{
				min = j;
			}
		}

		if (min != i)
		{
			temp = nums[i];
			nums[i] = nums[min];
			nums[min] = temp;
		}
	}
}

void BubbleSort(int* nums, int length)
{
	int temp;
	int flag = 1;//used to exit loop, if further swaps unnecessary

	for (int i = 0; i < length && flag; i++)
	{
		flag = 0;//reset flag
		for (int j = 0; j < length - 1; j++)
		{
			if (nums[j + 1] < nums[j])//swap '<' for '>' for descending order
			{
				temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
				flag = 1;
			}
		}
	}

}

//dir: 0=left,1=right
void ShiftChars(std::string& letters, int length, int amount, int dir)
{
	char temp;
	char last;

	if (dir == 0)//move left
	{
		last = letters[length-1];//set start value

		for (int i = 0; i < amount; i++)
		{
			for (int i = length-1; i > 0; i--)
			{
				temp = letters[i - 1];
				letters[i - 1] = last;
				last = temp;
			}
			//move first element
			letters[length-1] = last;
		}
	}
	else//move right
	{
		last = letters[0];//set start value

		for (int i = 0; i < amount; i++)
		{
			for (int i = 0; i < length - 1; i++)
			{
				temp = letters[i + 1];
				letters[i + 1] = last;
				last = temp;
			}
			//move last element
			letters[0] = last;
		}
	}
}

void PrintArray(int* nums)
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << nums[i] << " ";
	}

	std::cout << std::endl << std::endl;

}

int main()
{
	//------------INSERTION SORT-------------
	std::cout << "\nInsertion Sort: \n";
	//array of numbers to sort
	int nums[10] = { 10,9,13,22,16,17,55,8,12,5 };

	PrintArray(nums);

	InsertionSort(nums, 10);

	PrintArray(nums);


	//------------SELECTION SORT-------------
	std::cout << "\nSelection Sort: \n";
	//array of numbers to sort
	int nums2[10] = { 10,9,13,22,16,17,55,8,12,5 };

	PrintArray(nums2);

	SelectionSort(nums2, 10);

	PrintArray(nums2);

	//------------BUBBLE SORT-------------
	std::cout << "\nBubble Sort: \n";
	//array of numbers to sort
	int nums3[10] = { 10,9,13,22,16,17,55,8,12,5 };

	PrintArray(nums3);

	BubbleSort(nums3, 10);

	PrintArray(nums3);


	//------------SHIFT CHARS-------------
	std::cout << "\nString Character Shifting: \n";
	std::string letters = "abcdefghij";
	std::cout << letters << std::endl;
	
	ShiftChars(letters, 10, 4, 1);
	std::cout << letters << std::endl;

	ShiftChars(letters, 10, 3, 0);
	std::cout << letters << std::endl;


	//wait for input
	char tempvar;
	std::cin >> tempvar;

	return 1;

}