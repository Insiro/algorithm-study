/**
 * Algorithms : 
 * PK(E,M), SK(D,M)
 * Seta(M) - Seta(P)Seta(Q)=T   P, Q : prime
 * E*D = 1 (mod T)
 * C = N^E mod M
 * C^D  modM = N^ED mod M = N
 * find Original value of C
 * input test
 * N E C  -PK for modulus, PK, EncrytedData (one int)
 * 
 **/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int getPrimeFactor(int MaxNum);
int getSecretKey(int publicKey, int Seta_ModulusKey);
int Decrypt(int cryptedValue, int secretKey, int modulurValue);
int squareModulus(int value, int divider, int target);
int main()
{
    int N, E, CryptedData, PrimeFactor, secretKey;
    FILE *fptr = fopen("input.txt", "r");
    fscanf(fptr, "%d %d %d", &N, &E, &CryptedData); // Modulur , PublicKey, Data
    PrimeFactor = getPrimeFactor(N);
    int Seta_ModulusKey = (N / PrimeFactor - 1) * (PrimeFactor - 1);
    secretKey = getSecretKey(E, Seta_ModulusKey);
    // printf("Public Key : %d\n", E);
    // printf("Secret Value : %d\n", CryptedData);
    // printf("PrimeFactor P : %d\n", PrimeFactor);
    // printf("SecretKey : %d\n", secretKey);
    printf("Natural Data : %d\n", Decrypt(CryptedData, secretKey, N));
}
int getSecretKey(int publicKey, int Seta_ModulusKey)
{
    int secretKey = 2;
    while (secretKey * publicKey % Seta_ModulusKey != 1)
    {
        secretKey++;
    }
    return secretKey;
}
int Decrypt(int cryptedValue, int secretKey, int modulurValue)
{
    return squareModulus(cryptedValue % modulurValue, modulurValue, secretKey);
}

int squareModulus(int value, int divider, int target)
{
    int calced;
    if (target <= 2)
    {
        calced = pow(value, target);
    }
    else
    {
        calced = squareModulus(value, divider, target / 2);
        calced *= calced;
        calced %= divider;
        calced = (target % 2 == 1) ? calced * value % divider : calced;
    }
    return calced;
}
int getPrimeFactor(int MaxNum)
{
    if (MaxNum % 2 == 0)
    {
        return 2;
    }
    int sqrtMaxNum = sqrt(MaxNum);
    int *primeTable = (int *)calloc(sqrtMaxNum - 2, sizeof(int));
    for (int i = 3; i < sqrtMaxNum; i = i + 2)
    {
        if (primeTable[i - 3] == 1)
        {
            continue;
        }
        if (MaxNum % i == 0)
        {
            return i;
        }
        for (int j = i, q = 1; j * q < sqrtMaxNum; q++)
        {
            primeTable[j * q - 3] = 1;
        }
    }
}