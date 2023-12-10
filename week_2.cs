using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics.Eventing.Reader;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace _005_ClosestPair
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    //IComparer는 Array.sort() 메소드에서 사용할 비교를 위한 인터페이스
    public class XComparer : IComparer
    {
        public int Compare(object x, object y)
        {
            //return (int)(((Point)x).X-((Point)y).X);
            if (((Point)x).X - ((Point)y).X > 0)
                return 1;
            else
                return -1;
        }
    }
    public partial class MainWindow : Window
    {
        //const int P = 10000;
        int noOfpoints;
        Point[] points;
        public MainWindow()
        {
            InitializeComponent();
        }

        private void btnCreate_Click(object sender, RoutedEventArgs e)
        {
            can.Children.Clear();
            noOfpoints = int.Parse(txtNo.Text);
            points = new Point[noOfpoints];
            MakePointArray();
            SortPointArray();
        }

        private void SortPointArray()
        {
            IComparer xComp = new XComparer();
            Array.Sort(points, xComp);
            PrintPoints();
        }

        private void PrintPoints()
        {
            //foreach(Point p in points)
            for (int i = 0; i < noOfpoints; i++)
            {
                Console.WriteLine(points[i] + "," + points[i].Y);
            }

        }

        // random하게 점의 좌표를 만들고 배열에 저장
        private void MakePointArray()
        {
            Random r = new Random();

            for (int i = 0; i < noOfpoints; i++)
            {
                points[i] = new Point(r.NextDouble() * can.Width, r.NextDouble() * can.Height);
            }
            foreach (var p in points)
            {
                Rectangle rect = new Rectangle();
                rect.Width = rect.Height = 3;
                rect.Stroke = Brushes.Black;
                Canvas.SetLeft(rect, p.X - 1);
                Canvas.SetTop(rect, p.Y - 1);
                can.Children.Add(rect);
            }
        }

        // Brute Force 방법
        private void btnBrute_Click(object sender, RoutedEventArgs e)
        {
            var watch = System.Diagnostics.Stopwatch.StartNew();
            PointPair result = FindClosestPair(points, 0, noOfpoints - 1);

            HighLight(result);
            MessageBox.Show(String.Format("({0}, {1}) - ({2}, {3}) = {4}",
                result.P1.X, result.P1.Y, result.P2.X, result.P2.Y,
                result.Dist));
            watch.Stop();
            long tickBrute = watch.ElapsedTicks;
            long msBrute = watch.ElapsedMilliseconds;
            txtBrute.Text = "Brute Force : " + tickBrute
              + " Ticks, " + msBrute + " ms";


        }

        private void HighLight(PointPair result)
        {
            //Line l = new Line();
            //l.X1 = result.P1.X-1;
            //l.Y1 = result.P1.Y;
            //l.X2 = result.P2.X+1;
            //l.Y2 = result.P2.Y;
            //l.Stroke = Brushes.Red;
            //l.StrokeThickness = 3;
            //can.Children.Add(l);

            //사각형으로 두 점을 둘러싸도록 그린다
            int size = 12;
            Rectangle r = new Rectangle();
            double left = 0;
            if (result.P1.X < result.P2.X)
            {
                r.Width = result.P2.X - result.P1.X + size;
                left = result.P1.X - size / 2;
            }
            else
            {
                r.Width = result.P1.X - result.P2.X + size;
                left = result.P2.X - size / 2;
            }
            double top = 0;
            if (result.P1.Y < result.P2.Y)
            {
                r.Height = result.P2.Y - result.P1.Y + size;
                top = result.P1.Y - size / 2;
            }
            else
            {
                r.Height = result.P1.Y - result.P2.Y + size;
                top = result.P2.Y - size / 2;
            }

            r.Stroke = Brushes.Red;
            r.StrokeThickness = 1;
            Canvas.SetLeft(r, left);
            Canvas.SetTop(r, top);
            can.Children.Add(r);


        }

        private PointPair FindClosestPair(Point[] points, int start, int end)
        {
            double min = double.MaxValue;
            int minI = 0, minJ = 0; // 최근점 점 두개의 points[] 인덱스

            for (int i = start; i < end - 1; i++)
                for (int j = i + 1; j < end; j++)
                    if (Dist(i, j) < min)
                    {
                        min = Dist(i, j);
                        minI = i;
                        minJ = j;
                    }
            PointPair pp = new PointPair(points[minI], points[minJ], min);
            return pp;
        }

        private double Dist(int i, int j)
        {
            return Math.Sqrt(Math.Pow(points[i].X - points[j].X, 2) +
                Math.Pow(points[i].Y - points[j].Y, 2));
        }

        private void btnDivde_Click(object sender, RoutedEventArgs e)
        {
            var watch = System.Diagnostics.Stopwatch.StartNew();
            PointPair result = FindClosestPairDC(points, 0, noOfpoints - 1); //포인트 배열의 인덱스 
            HighLight(result);
            MessageBox.Show(String.Format("({0}, {1}) - ({2}, {3}) = {4}",
                result.P1.X, result.P1.Y, result.P2.X, result.P2.Y,
                result.Dist));

            watch.Stop();
            long tickDivde = watch.ElapsedTicks;
            long msDivde = watch.ElapsedMilliseconds;
            txtDivide.Text = "Divide and Conquer : " + tickDivde
              + " Ticks, " + msDivde + " ms";


        }

        private PointPair FindClosestPairDC(Point[] points, int left, int right)
        {
            Console.WriteLine("FCDC(" + left + "," + right + ")");
            if (right - left + 1 <= 10)
                return FindClosestPair(points, left, right);
            int mid = left + (right - left) / 2;
            CenterLine(mid);

            PointPair cPL = FindClosestPairDC(points, left, mid);
            PointPair cPR = FindClosestPairDC(points, mid + 1, right);
            double d = Math.Min(cPL.Dist, cPR.Dist);
            PointPair cPC = FindMidRange(points, mid, d);

            return MinPointPair(cPL, cPR, cPC);
        }

        private void CenterLine(int mid)
        {
            Line line = new Line();
            line.X1 = line.X2 = mid;
            line.Y1 = 0;
            line.Y2 = can.Height;
            line.Stroke = Brushes.Blue;
            line.StrokeThickness = 1;
            can.Children.Add(line);
        }

        private PointPair MinPointPair(PointPair cPL, PointPair cPR, PointPair cPC)
        {
            if (cPL.Dist <= cPR.Dist && cPL.Dist <= cPC.Dist)
                return cPL;
            else if (cPR.Dist <= cPL.Dist && cPR.Dist <= cPC.Dist)
                return cPR;
            else
                return cPC;
        }

        private PointPair FindMidRange(Point[] points, int mid, double d)
        {
            int left = 0, right = 0;

            for (int i = mid; i >= 0; i--)
                if (points[mid].X - points[i].X > d)
                {
                    left = i;
                    break;
                }
            for (int i = mid; i < points.Length; i++)
                if (points[i].X - points[mid].X > d)
                {
                    right = i;
                    break;
                }
            return FindClosestPair(points, left, right);
        }
    }
}