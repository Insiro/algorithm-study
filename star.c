/** n행까지 별을 출력하시오      N=3*(2^k)                        *                        
                      * *                       
                     *****                      
                    *     *                     
                   * *   * *                    
                  ***** *****                   
                 *           *                  
                * *         * *                 
               *****       *****                
              *     *     *     *               
             * *   * *   * *   * *              
            ***** ***** ***** *****             
           *                       *            
          * *                     * *           
         *****                   *****          
        *     *                 *     *         
       * *   * *               * *   * *        
      ***** *****             ***** *****       
     *           *           *           *      
    * *         * *         * *         * *     
   *****       *****       *****       *****    
  *     *     *     *     *     *     *     *   
 * *   * *   * *   * *   * *   * *   * *   * *  
***** ***** ***** ***** ***** ***** ***** *****
**/
#include <stdio.h>
#define A 3073
char arr[A][A * 2] = {' '};
void star(int, int, int);
int main()
{
    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < A * 2; j++)
        {
            arr[i][j] = ' ';
        }
    }
    int n, x, y;
    scanf("%d", &n);

    star(n, n, 0);

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            printf("\n");
        for (int j = 0; j < 2 * n; j++)
        {
            printf("%c", arr[i][j]);
        }
    }

    return 0;
}

void star(int n, int x, int y)
{
    int p = n / 2;
    if (n == 3)
    {
        arr[y][x] = '*';
        arr[y + 1][x - 1] = '*';
        arr[y + 1][x + 1] = '*';
        arr[y + 2][x - 2] = '*';
        arr[y + 2][x - 1] = '*';
        arr[y + 2][x] = '*';
        arr[y + 2][x + 1] = '*';
        arr[y + 2][x + 2] = '*';
        return;
    }
    star(p, x - p, y + p);
    star(p, x + p, y + p);
    star(p, x, y);
}