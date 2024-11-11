#include "pch.h"
#include "../DFSandBFS/Graph.cpp"

TEST(GraphTest, AddEdgesAndDisplay1) {
    Graph g(5);

    // ��������� ����
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);

    // ��������� ��������� �����
    testing::internal::CaptureStdout();
    g.display();
    std::string output = testing::internal::GetCapturedStdout();

    // ��������� �����
    std::string expectedOutput = "Node 0: -> 1 -> 2\nNode 1: -> 0 -> 3\nNode 2: -> 0\nNode 3: -> 1\nNode 4:\n";

    EXPECT_EQ(output, expectedOutput);
}
TEST(GraphTest, AddEdgesAndDisplay2) {
    Graph g(10);

    // ��������� ����
    g.addEdge(0, 1);
    g.addEdge(0, 5);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 7);
    g.addEdge(6, 7);
    g.addEdge(6, 8);
    g.addEdge(7, 9);

    // ��������� ��������� �����
    testing::internal::CaptureStdout();
    g.display();
    std::string output = testing::internal::GetCapturedStdout();

    // ��������� �����
    std::string expectedOutput = "Node 0: -> 1 -> 5\nNode 1: -> 0 -> 2 -> 3\nNode 2: -> 1\nNode 3: -> 1 -> 4\nNode 4: -> 3\nNode 5: -> 0 -> 6 -> 7\nNode 6: -> 5 -> 7 -> 8\nNode 7: -> 5 -> 6 -> 9\nNode 8: -> 6\nNode 9: -> 7\n";

    EXPECT_EQ(output, expectedOutput);
}
TEST(GraphTest, AddEdgesAndDisplay3) {
    Graph g(8);

    // ��������� ����
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(2, 4);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 6);

    // ��������� ��������� �����
    testing::internal::CaptureStdout();
    g.display();
    std::string output = testing::internal::GetCapturedStdout();

    // ��������� �����
    std::string expectedOutput = "Node 0: -> 1 -> 3\nNode 1: -> 0\nNode 2: -> 4\nNode 3: -> 0\nNode 4: -> 2 -> 5 -> 6\nNode 5: -> 4 -> 6\nNode 6: -> 4 -> 5\nNode 7:\n";

    EXPECT_EQ(output, expectedOutput);
}

TEST(GraphTest, DFS1) {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    // ����������� ����������� �����
    testing::internal::CaptureStdout();

    g.DFS(2); // ��������� DFS � ��������� �������� 0

    // �������� ����������� �����
    std::string output = testing::internal::GetCapturedStdout();

    // ��������� �����
    std::string expectedOutput = "����� � �������\n2 4 0 1 3 \n"; // ������ ���������� ����������

    // ���������, ��� ����� ��������� � ���������
    EXPECT_EQ(output, expectedOutput);
}
TEST(GraphTest, DFS2) {
    Graph g(10);
    g.addEdge(0, 1);
    g.addEdge(0, 5);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 7);
    g.addEdge(6, 7);
    g.addEdge(6, 8);
    g.addEdge(7, 9);

    // ����������� ����������� �����
    testing::internal::CaptureStdout();

    g.DFS(0); // ��������� DFS � ��������� �������� 0

    // �������� ����������� �����
    std::string output = testing::internal::GetCapturedStdout();

    // ��������� �����
    std::string expectedOutput = "����� � �������\n0 5 7 9 6 8 1 3 4 2 \n"; // ������ ���������� ����������

    // ���������, ��� ����� ��������� � ���������
    EXPECT_EQ(output, expectedOutput);
}
TEST(GraphTest, DFS3) {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    // ����������� ����������� �����
    testing::internal::CaptureStdout();

    g.DFS(0); // ��������� DFS � ��������� �������� 0

    // �������� ����������� �����
    std::string output = testing::internal::GetCapturedStdout();

    // ��������� �����
    std::string expectedOutput = "����� � �������\n0 2 6 5 1 4 3 \n"; // ������ ���������� ����������

    // ���������, ��� ����� ��������� � ���������
    EXPECT_EQ(output, expectedOutput);
}
TEST(GraphTest, BFS1) {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    // ����������� ����������� �����
    testing::internal::CaptureStdout();

    g.BFS(0); // ��������� BFS � ��������� �������� 0

    // �������� ����������� �����
    std::string output = testing::internal::GetCapturedStdout();

    // ��������� �����
    std::string expectedOutput = "����� � ������\n0 1 2 3 4 5 6 \n"; // ������ ���������� ����������

    // ���������, ��� ����� ��������� � ���������
    EXPECT_EQ(output, expectedOutput);
}
TEST(GraphTest, BFS2) {
    Graph g(10);
    g.addEdge(0, 1);
    g.addEdge(0, 5);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 7);
    g.addEdge(6, 8);
    g.addEdge(7, 9);

    // ����������� ����������� �����
    testing::internal::CaptureStdout();

    g.BFS(3); // ��������� BFS � ��������� �������� 0

    // �������� ����������� �����
    std::string output = testing::internal::GetCapturedStdout();

    // ��������� �����
    std::string expectedOutput = "����� � ������\n3 1 4 0 2 5 6 7 8 9 \n"; // ������ ���������� ����������

    // ���������, ��� ����� ��������� � ���������
    EXPECT_EQ(output, expectedOutput);
}
TEST(GraphTest, BFS3) {
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(1, 7);
    g.addEdge(2, 7);

    // ����������� ����������� �����
    testing::internal::CaptureStdout();

    g.BFS(0); // ��������� BFS � ��������� �������� 0

    // �������� ����������� �����
    std::string output = testing::internal::GetCapturedStdout();

    // ��������� �����
    std::string expectedOutput = "����� � ������\n0 1 2 3 4 7 5 6 \n"; // ������ ���������� ����������

    // ���������, ��� ����� ��������� � ���������
    EXPECT_EQ(output, expectedOutput);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

