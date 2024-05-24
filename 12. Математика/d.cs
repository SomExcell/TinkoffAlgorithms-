using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithms
{
    class Program
    {
		public static void Main()
		{
            long n = Convert.ToInt64(Console.ReadLine());
            long result = 1;
            int m = 0;
            for (int i = 1; i < n+1; i++)
            {
                int copy = i;
                while (copy % 2 == 0)
                {
                    copy /= 2;
                    m++;
                }
                while(copy % 5 == 0)
                {
                    copy /= 5;
                    m--;
                }
                result = result * copy % 10;
            }

            result = (result << m) % 10;
            Console.WriteLine(result);
            Console.ReadKey();
		}
	}
}