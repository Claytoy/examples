using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ZHDM
{
    class gg
    {
        public Calculate cal = new Calculate();
        public double S1 = 0;
        public double S2 = 0;
        public void dataIn(string filepath)//数据导入
        {
            string line;
            string[] strs;
            StreamReader sr = new StreamReader(filepath);
            Data kp = new Data();
            line = sr.ReadLine();
            strs = line.Split(',');
            kp.H_name = strs[0];
            kp.Height = double.Parse(strs[1]);
            cal.data.Add(kp);

            line = sr.ReadLine();
            strs = line.Split(',');
            double a = 0;
            a = strs.Count();
            for (int i = 0; i < strs.Count(); i++)
            {
                K_point kp6 = new K_point();
                kp6.Point = strs[i];
                cal.K_points.Add(kp6);

            }

            //for (int i = 0; i < 2; i++)
            //{
            //    line = sr.ReadLine();
            //    strs = line.Split(',');
            //    test kp2 = new test();
            //    kp2.T_name = strs[0];
            //    kp2.T_X = double.Parse(strs[1]);
            //    kp2.T_Y = double.Parse(strs[2]);
            //    cal.tests.Add(kp2);
            //}

            line = sr.ReadLine();

            while ((line = sr.ReadLine()) != null)
            {

                strs = line.Split(',');

                for (int i = 0; i < a; i++)
                {
                    if (strs[0] == cal.K_points[i].Point)
                    {
                        cal.K_points[i].X = double.Parse(strs[1]);
                        cal.K_points[i].Y = double.Parse(strs[2]);
                        cal.K_points[i].Z = double.Parse(strs[3]);

                    }
                }
                Point kp1 = new Point();
                kp1.Name = strs[0];
                kp1.X = double.Parse(strs[1]);
                kp1.Y = double.Parse(strs[2]);
                kp1.Z = double.Parse(strs[3]);
                cal.points.Add(kp1);

            }
        }

        public void Zduanmian()
        {
            //计算纵断面的长度 
            List<Point> Temp = new List<Point>();//L存储点
            double D = 0;
            for (int i = 0; i < cal.K_points.Count - 1; i++)
            {
                D = D + count.longth(cal.K_points[i + 1].X, cal.K_points[i + 1].Y, cal.K_points[i].X, cal.K_points[i].Y);
            }

            //计算内插点的平面坐标
            double di = 0;
            di = count.longth(cal.K_points[1].X, cal.K_points[1].Y, cal.K_points[0].X, cal.K_points[0].Y);
            for (int i = 10; i < di; i += 10)
            {

                double xi = 0;
                double yi = 0;
                Z_Point kp3 = new Z_Point();
                xi = cal.K_points[0].X + i * Math.Cos(count.fangwei(cal.K_points[1].Y, cal.K_points[0].Y, cal.K_points[1].X, cal.K_points[0].X) / 180 * Math.PI);
                yi = cal.K_points[0].Y + i * Math.Sin(count.fangwei(cal.K_points[1].Y, cal.K_points[0].Y, cal.K_points[1].X, cal.K_points[0].X) / 180 * Math.PI);
                kp3.X = xi;
                kp3.Y = yi;
                cal.Z_points.Add(kp3);
            }
            for (int i = 1; i < cal.K_points.Count - 1; i++)
            {
                di = count.longth(cal.K_points[i + 1].X, cal.K_points[i + 1].Y, cal.K_points[i].X, cal.K_points[i].Y);
                for (int j = 10; j < di; j += 10)
                {
                    Z_Point kp4 = new Z_Point();
                    double xi = 0;
                    double yi = 0;
                    xi = cal.K_points[i].X + j * Math.Cos(count.fangwei(cal.K_points[i + 1].Y, cal.K_points[i].Y, cal.K_points[i + 1].X, cal.K_points[i].X) / 180 * Math.PI);
                    yi = cal.K_points[i].Y + j * Math.Sin(count.fangwei(cal.K_points[i + 1].Y, cal.K_points[i].Y, cal.K_points[i + 1].X, cal.K_points[i].X) / 180 * Math.PI);
                    kp4.X = xi;
                    kp4.Y = yi;
                    cal.Z_points.Add(kp4);
                }
            }
          
            for (int i = 0; i < cal.Z_points.Count; i++)
            {
                
                for (int j = 0; j < cal.points.Count; j++)
                {
                    Point kp7 = new Point();
                    kp7 = cal.points[j];
                    double l = 0;
                    l = count.longth(cal.points[j].X, cal.points[j].Y, cal.Z_points[i].X, cal.Z_points[i].Y);
                    kp7.L = l;
                    Temp.Add(kp7);
                }

                for (int j = 0; j < Temp.Count-1; j++)
                {
                    for (int k = 0; k < Temp.Count - j - 1; k++)
                    {
                        if (Temp[k+1].L < Temp[k].L)
                        {
                            Point Tp = new Point();
                            Tp = Temp[k];
                            Temp[k] = Temp[k+1];
                            Temp[k+1] = Tp;

               
                        }
                    }
                }
                for(int j = 0; j < 5; j++)
                {
                    cal.Z_points[i].Near51.Add(Temp[j]);
                }

                Temp.Clear();

            }
            //计算纵断面面积
            double a = 0;
            double b = 0;
            List<double> H = new List<double>();
            for(int i = 0;i < cal.Z_points.Count; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    a = a + (cal.Z_points[i].Near51[j].Z/cal.Z_points[i].Near51[j].L);
                    b = b + (1 / cal.Z_points[i].Near51[j].L);
                }
                double h = 0;
                h = a / b;
                H.Add(h);
            }

            double S = 0;
            for(int i = 0;i < cal.Z_points.Count-1;i++)
            {
                S = S + ((H[i] + H[i + 1] - 2 * cal.data[0].Height) * (cal.Z_points[i + 1].Y - cal.Z_points[i].Y) / 2);
            }
            S1 = S;
        }

        public void Hduanmian()
        {
            List<Point> Temp = new List<Point>();//L存储点
            //计算横断面中心点
            List<double> Mid_X = new List<double>();
            List<double> Mid_Y = new List<double>();
            for (int i = 0; i < cal.K_points.Count - 1; i++)
            {
                double x = 0;
                x = (cal.K_points[i].X + cal.K_points[i + 1].X) / 2;
                double y = 0;
                y = (cal.K_points[i].Y + cal.K_points[i + 1].Y) / 2;
                x = Math.Round(x, 3);
                y = Math.Round(y, 3);
                Mid_X.Add(x);
                Mid_Y.Add(y);
            }

            //计算横断面插值的平面坐标和高程
            for (int i = 0; i < Mid_X.Count; i++)
            {
                for (int j = 5; j < 26; j += 5)
                {
                    H_Point kp5 = new H_Point();
                    double x = 0;
                    x = Mid_X[i] + j * Math.Cos((count.fangwei(cal.K_points[i + 1].Y, cal.K_points[i].Y, cal.K_points[i + 1].X, cal.K_points[i].X) + 90) / 180 * Math.PI);
                    x = Math.Round(x, 3);
                    double y = 0;
                    y = Mid_Y[i] + j * Math.Cos((count.fangwei(cal.K_points[i + 1].Y, cal.K_points[i].Y, cal.K_points[i + 1].X, cal.K_points[i].X) + 90) / 180 * Math.PI);
                    y = Math.Round(y, 3);
                    kp5.X = x;
                    kp5.Y = y;
                    cal.H_points.Add(kp5);
                }

                for (int j = -5; j < -26; j -= 5)
                {
                    H_Point kp6 = new H_Point();
                    double x = 0;
                    x = Mid_X[i] + j * Math.Cos((count.fangwei(cal.K_points[i + 1].Y, cal.K_points[i].Y, cal.K_points[i + 1].X, cal.K_points[i].X) + 90) / 180 * Math.PI);
                    x = Math.Round(x, 3);
                    double y = 0;
                    y = Mid_Y[i] + j * Math.Cos((count.fangwei(cal.K_points[i + 1].Y, cal.K_points[i].Y, cal.K_points[i + 1].X, cal.K_points[i].X) + 90) / 180 * Math.PI);
                    y = Math.Round(y, 3);
                    kp6.X = x;
                    kp6.Y = y;
                    cal.H_points.Add(kp6);
                }
            }

            for (int i = 0; i < cal.H_points.Count; i++)
            {

                for (int j = 0; j < cal.points.Count; j++)
                {
                    Point kp7 = new Point();
                    kp7 = cal.points[j];
                    double l = 0;
                    l = count.longth(cal.points[j].X, cal.points[j].Y, cal.H_points[i].X, cal.H_points[i].Y);
                    kp7.L = l;
                    Temp.Add(kp7);
                }

                for (int j = 0; j < Temp.Count - 1; j++)
                {
                    for (int k = 0; k < Temp.Count - j - 1; k++)
                    {
                        if (Temp[k + 1].L < Temp[k].L)
                        {
                            Point Tp = new Point();
                            Tp = Temp[k];
                            Temp[k] = Temp[k + 1];
                            Temp[k + 1] = Tp;


                        }
                    }
                }
                for (int j = 0; j < 5; j++)
                {
                    cal.H_points[i].Near51.Add(Temp[j]);
                }

                Temp.Clear();

            }
            //计算横断面面积
            double a = 0;
            double b = 0;
            List<double> H = new List<double>();
            for (int i = 0; i < cal.H_points.Count; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    a = a + (cal.H_points[i].Near51[j].Z / cal.H_points[i].Near51[j].L);
                    b = b + (1 / cal.H_points[i].Near51[j].L);
                }
                double h = 0;
                h = a / b;
                H.Add(h);
            }

            double S = 0;
            for (int i = 0; i < cal.H_points.Count - 1; i++)
            {
                S = S + ((H[i] + H[i + 1] - 2 * cal.data[0].Height) * (cal.H_points[i + 1].Y - cal.H_points[i].Y) / 2);
            }
            S2 = S;
        }
    }
    
}
