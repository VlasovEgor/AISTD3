#include "pch.h"
#include "CppUnitTest.h"
#include "..//AISTD3.0/AISTD3.0.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestAISTD30
{
	TEST_CLASS(TestAISTD30)
	{
	public:
		
		TEST_METHOD(insert)
		{
			Branch_tree tree(1);
			tree.insert(2);
			tree.insert(3);
			Assert::AreEqual(tree.contains(3), true);
			Assert::AreEqual(tree.contains(5), false);
		}

		TEST_METHOD(remove)
		{
			Branch_tree tree(1);
			tree.insert(2);
			tree.insert(3);
			Assert::AreEqual(tree.contains(1), true);
			Assert::AreEqual(tree.contains(2), true);
			Assert::AreEqual(tree.contains(3), true);
			tree.remove(2);
			Assert::AreEqual(tree.contains(1), true);
			Assert::AreEqual(tree.contains(2), false);
			Assert::AreEqual(tree.contains(3), true);
		}

		TEST_METHOD(contains)
		{
			Branch_tree tree(1);
			tree.insert(2);
			tree.insert(3);
			tree.insert(4);
			tree.insert(5);
			Assert::AreEqual(tree.contains(4), true);
			Assert::AreEqual(tree.contains(6), false);
		}


		TEST_METHOD(dft)
		{
			Branch_tree tree;
			Iterator* iter = tree.create_dft_iterator();
			int ArrTree[] = { 7, 9, 10, 3, 8, 4, 1 };
			for (int i = 0; i < 6; i++)
				tree.insert(ArrTree[i]);
			int ArrDft[] = { 7, 3, 1, 4, 9, 8, 10 };
			Iterator* iter = tree.create_dft_iterator();
			for (int i = 0; i < 6; i++)
				Assert::AreEqual(iter->intnext(), ArrDft[i]);
		}
		TEST_METHOD(bft)
		{
			Branch_tree tree;
			Iterator* iter = tree.create_bft_iterator();
			int ArrTree[] = { 7, 9, 10, 3, 8, 4, 1};
			for (int i = 0; i < 6; i++)
				tree.insert(ArrTree[i]);
			int ArrBft[] = { 7, 3, 9, 1, 4, 8, 10};
			Iterator* iter = tree.create_bft_iterator();
			for (int i = 0; i < 6; i++)
				Assert::AreEqual(iter->intnext(), ArrBft[i]);
		}
	};
}
