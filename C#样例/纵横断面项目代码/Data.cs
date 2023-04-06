using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ZHDM
{
    public class Data
    {
        private string h_name;//参考面高程名
        private double height = 0;//参考面高程

        public double Height
        {
            get
            {
                return height;
            }

            set
            {
                height = value;
            }
        }

        public string H_name
        {
            get
            {
                return h_name;
            }

            set
            {
                h_name = value;
            }
        }
    }

    public class Point
    {
        private string name;//点名
        private double x = 0;//X
        private double y = 0;//Y
        private double z = 0;//Z
        private double l = 0;//L
        public string Name
        {
            get
            {
                return name;
            }

            set
            {
                name = value;
            }
        }

        public double X
        {
            get
            {
                return x;
            }

            set
            {
                x = value;
            }
        }

        public double Y
        {
            get
            {
                return y;
            }

            set
            {
                y = value;
            }
        }

        public double Z
        {
            get
            {
                return z;
            }

            set
            {
                z = value;
            }
        }

        public double L
        {
            get
            {
                return l;
            }

            set
            {
                l = value;
            }
        }
    }

    public class test
    {
        private string t_name;//测试点名
        private double t_X = 0;//测试X
        private double t_Y = 0;//测试Y

        public string T_name
        {
            get
            {
                return t_name;
            }

            set
            {
                t_name = value;
            }
        }

        public double T_X
        {
            get
            {
                return t_X;
            }

            set
            {
                t_X = value;
            }
        }

        public double T_Y
        {
            get
            {
                return t_Y;
            }

            set
            {
                t_Y = value;
            }
        }
    }

    public class K1
    {
        private string name;
        private double longth = 0;
        private double height = 0;


        public string Name
        {
            get
            {
                return name;
            }

            set
            {
                name = value;
            }
        }

        public double Longth
        {
            get
            {
                return longth;
            }

            set
            {
                longth = value;
            }
        }

        public double Height
        {
            get
            {
                return height;
            }

            set
            {
                height = value;
            }
        }
    }

    public class K_point
    {
        private string point;
        private double x = 0;
        private double y = 0;
        private double z = 0;

        public string Point
        {
            get
            {
                return point;
            }

            set
            {
                point = value;
            }
        }

        public double X
        {
            get
            {
                return x;
            }

            set
            {
                x = value;
            }
        }

        public double Y
        {
            get
            {
                return y;
            }

            set
            {
                y = value;
            }
        }

        public double Z
        {
            get
            {
                return z;
            }

            set
            {
                z = value;
            }
        }
    }

    public class Z_Point
    {
        private double x = 0;
        private double y = 0;
        private double z = 0;
        public string name;
        public double l = 0;
        List<Point> Near5 = new List<Point>();
        public double X
        {
            get
            {
                return x;
            }

            set
            {
                x = value;
            }
        }

        public double Y
        {
            get
            {
                return y;
            }

            set
            {
                y = value;
            }
        }

        public double Z
        {
            get
            {
                return z;
            }

            set
            {
                z = value;
            }
        }

        public List<Point> Near51
        {
            get
            {
                return Near5;
            }

            set
            {
                Near5 = value;
            }
        }
    }

    public class H_Point
    {
        private double x = 0;
        private double y = 0;
        private double z = 0;
        List<Point> Near5 = new List<Point>();

        public double X
        {
            get
            {
                return x;
            }

            set
            {
                x = value;
            }
        }

        public double Y
        {
            get
            {
                return y;
            }

            set
            {
                y = value;
            }
        }

        public double Z
        {
            get
            {
                return z;
            }

            set
            {
                z = value;
            }
        }

        public List<Point> Near51
        {
            get
            {
                return Near5;
            }

            set
            {
                Near5 = value;
            }
        }
    }

    public class Calculate
    {
        public List<Data> data = new List<Data>();
        public List<test> tests = new List<test>();
        public List<Point> points = new List<Point>();
        public List<K1> k1 = new List<K1>();
        public List<K_point> K_points = new List<K_point>();
        public List<Point> KP = new List<Point>();
        public List<Z_Point> Z_points = new List<Z_Point>();
        public List<H_Point> H_points = new List<H_Point>();
    }
}

