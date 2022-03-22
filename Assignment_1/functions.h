

#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

void MySAGInit(int N,int *stream);
void MySAGInsert(int N,int *stream);
int MySAGMax(int N,int *stream);
int MySAGMin(int N,int *stream);
int MySAGAvg(int N,int *stream);
int MySAGFreq(int N,int *stream,int x);

#endif