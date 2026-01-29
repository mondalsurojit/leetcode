int maxArea(int* height, int heightSize) {
    int *front, *rear, area = 0, maxArea = 0, i = heightSize;
    front = height;
    rear = height + heightSize - 1;
    while (i > 0) {
        area = (*front) < (*rear) ? (*front) * (rear-front) : (*rear) * (rear-front);
        if (area > maxArea)
            maxArea = area;
        if (*front < *rear)
            front++;
        else
            rear--;
        i--;
    }
    return maxArea;
}