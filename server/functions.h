#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <QByteArray>
#include <QString>
#include <QList>
#include <QVector>
#include <QDebug>

void heapify_first(QVector<int>& arr, int n, int i);

bool heapify(QVector<int>& arr, int n, int i, int& max_step);

void heapSort(QVector<int>& arr, int& max_step);

QByteArray pyramid_sort(QString array, int step);

QByteArray InvalidRequest();

QByteArray parse(QString message);

#endif // FUNCTIONS_H
