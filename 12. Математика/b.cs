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
            int n = (int)1e6;
            var simpleValues = new List<long>(100000);
			var values = new List<long>((int)(n));
			for(int i = 0;i < n;i++)
            {
				values.Add(0);
            }
            for (int i = 2; i < n; i++)
            {
                if(values[i] == 0)
                {
                    values[i] = i;
                    simpleValues.Add(i);
                }
                foreach(int x in simpleValues)
                {
                    if (x > values[i] ||  (long)(x) * (long)(i) >= n)
                    {
                        break;
                    }
                    values[x * i] = x;
                }
            }

            StringBuilder result = new StringBuilder();
            long value = Convert.ToInt64(Console.ReadLine());
            int count = 0;
            int lastVal = -1;
            bool havePow = false;
            for (int i = 0; value!=1 && i < simpleValues.Count(); i++)
            {
                String c = Convert.ToString(simpleValues[i]);
                while(value % simpleValues[i] == 0)
                {
                    value /= simpleValues[i];
                    if(result.Length == 0)
                    {
                        result.Append(c);
                        lastVal = i;
                        count++;
                    }
                    else if(i == lastVal && havePow)
                    {
                        count++;
                    }
                    else if(i == lastVal && !havePow)
                    {
                        count++;
                        result.Append("^");
                        havePow = true;
                    }
                    else if(i != lastVal)
                    {
                        result.Append("*" + c);
                        havePow = false;
                        count = 1;
                        lastVal = i;
                    }
                }
                String p = Convert.ToString(count);
                if(count > 1)
                {
                    result.Append(p);
                }
                count = 0;
            }
            if(value != 1)
            {
                if(result.Length != 0) { result.Append('*'); }
                result.Append(Convert.ToString(value));
            }
            Console.WriteLine(result);
            Console.ReadKey();
		}
	}
}