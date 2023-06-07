#include <QtTest>
#include "../server/functions.h"

// add necessary includes here

class test_exam : public QObject
{
    Q_OBJECT

public:
    test_exam();
    ~test_exam();

private slots:
    void test_case1();

};

test_exam::test_exam()
{

}

test_exam::~test_exam()
{

}

void test_exam::test_case1()
{
    QVector<int> array1 = {1, 2, 3, 4, 5, 1, 4, 2, 3, 5};
    QVector<int> ans_array1 = {5, 1, 4, 4, 2, 1, 3, 2, 3, 5};
    int step1 = 2;
    heapSort(array1, step1);
    QVERIFY(array1 == ans_array1);

    QVector<int> array2 = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    QVector<int> ans_array2 = {19, 1, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 20};
    int step2 = 2;
    heapSort(array2, step2);
    QVERIFY(array2 == ans_array2);

    QVector<int> array3 = {0, 0, 0, 0, 0, 0};
    QVector<int> ans_array3 = {0, 0, 0, 0, 0, 0};
    int step3 = 10;
    heapSort(array3, step3);
    QVERIFY(array3 == ans_array3);

    QVector<int> array4 = {9, 3, 7, 3, 5, 1};
    QVector<int> ans_array4 = {1, 3, 3, 5, 7, 9};
    int step4 = 10;
    heapSort(array4, step4);
    QVERIFY(array4 == ans_array4);

    QVector<int> array5 = {3, 7, 13, 9, 4, 20};
    QVector<int> ans_array5 = {3, 9, 13, 7, 4, 20};
    int step5 = 1;
    heapSort(array5, step5);
    QVERIFY(array5 == ans_array5);

    QVector<int> array6 = {6, 3, 60, 1, 2, 4, 7};
    QVector<int> ans_array6 = {7, 3, 6, 1, 2, 4, 60};
    int step6 = 2;
    heapSort(array6, step6);
    QVERIFY(array6 == ans_array6);

    QVector<int> array7 = {3, 7, 1, 0, 4, 36, 1};
    QVector<int> ans_array7 = {1, 0, 1, 3, 4, 7, 36};
    int step7 = 10;
    heapSort(array7, step7);
    QVERIFY(array7 == ans_array7);

    QVector<int> array8 = {0, 2, 6, 3, 7, 1, 8, 3, 6};
    QVector<int> ans_array8 = {0, 3, 1, 3, 2, 6, 6, 7, 8};
    int step8 = 9;
    heapSort(array8, step8);
    QVERIFY(array8 == ans_array8);

    QVector<int> array9 = {0, 2, 73, 36, 2346, 6};
    QVector<int> ans_array9 = {2, 36, 6, 0, 73, 2346};
    int step9 = 3;
    heapSort(array9, step9);
    QVERIFY(array9 == ans_array9);

    QVector<int> array10 = {9, 4, 6, 2, 6, 23, 6, 137};
    QVector<int> ans_array10 = {6, 2, 6, 4, 6, 9, 23, 137};
    int step10 = 10;
    heapSort(array10, step10);
    QVERIFY(array10 == ans_array10);
}

QTEST_APPLESS_MAIN(test_exam)

#include "tst_test_exam.moc"
