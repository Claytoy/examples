using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ZHDM
{
    class count
    {
        public static double fangwei(double YB, double YA, double XB, double XA)
        {
            double alpha = 0;
            alpha = Math.Atan((YA - YB) / (XB - XA));
            alpha = alpha / Math.PI * 180;
            if ((YB - YA) > 0)
            {
                if ((XB - XA) > 0)
                {

                }
                else if ((XB - XA) < 0)
                {
                    alpha = 180 - alpha;
                }
                else if ((XB - XA) == 0)
                {
                    alpha = 90;
                }
            }
            else if ((YB - YA) < 0)
            {
                if ((XB - XA) > 0)
                {
                    alpha = 360 - alpha;
                }
                else if ((XB - XA) < 0)
                {
                    alpha = 180 + alpha;
                }
                else if ((XB - XA) == 0)
                {
                    alpha = 270;
                }
            }

            return alpha;
        }

        public static double longth(double x,double y,double xi,double yi)
        {
            double d = 0;
            d = Math.Sqrt(Math.Pow(x - xi, 2) + Math.Pow(y - yi, 2));
            d = Math.Round(d, 3);
            return d;
        }

        public static double S(double h,double hi,double h0,double li)
        {
            double S = 0;
            S = (h + hi - (2 * h0) / 2) * li;
            S = Math.Round(S, 3);
            return S;
        }

         
       
    }
}
