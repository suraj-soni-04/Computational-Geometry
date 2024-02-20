#include <iostream>
#include <vector>
#include <string>
#include "./headers/GeomVector.h"
#include "./headers/Writer.h"
#include "./headers/Matrix.h"
#include "./headers/Plane.h"
using namespace std;

int main()
{
    int choice;
    double x1, y1, z1; 
    double x2, y2, z2; 
    bool exitLoop = false;

    while (!exitLoop)
    {
        cout << "1. Check if two vectors are equal" << endl
                  << "2. Find magnitude of vector" << endl
                  << "3. Find normalized vector" << endl
                  << "4. Set new Vector-Length" << endl
                  << "5. Add Scalar Value to Vector" << endl
                  << "6. Subtract scalar value from vector" << endl
                  << "7. Multiply Vector by Scalar Value" << endl
                  << "8. Divide Vector by a Scalar Value" << endl
                  << "9. Add two Vectors" << endl
                  << "10. Dot-Product of two Vectors" << endl
                  << "11. Cross-Product of two Vectors" << endl
                  << "12. Find Direction Cosines of a Vector" << endl
                  << "13. Multiply Vector with Matrix" << endl
                  << "14. Find Distance between two Vectors" << endl
                  << "15. Find Distance between Vector and Plane" << endl
                  << "16. Find Angle between two Vectors" << endl
                  << "17. Find Angle between Vector and Plane" << endl
                  << "18. Find Projection on Vector" << endl
                  << "19. Find Projection on Plane " << endl
                  << "20. Angle between Vector and Axis" << endl
                  << "21. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter value for x, y and z" << endl;
            cin >> x1 >> y1 >> z1; 

            cout << "Enter value for x, y and z" << endl;
            cin >> x2 >> y2 >> z2; 

            GeomVector a(x1, y1, z1);
            GeomVector b(x2, y2, z2);
            if (a == b) cout << "Two vectors are equal." << endl;
            else cout << "Two vectors are not equal." << endl;
        }
        break;
        case 2:
        {
            cout << "Enter value for x, y and z" << endl;
            cin >> x1 >> y1 >> z1; 
            GeomVector a(x1, y1, z1);
            cout << "Magnitude of two vector is " << a.getMagnitude() << endl;
        }
        break;

        case 3:
        {
            cout << "Enter value for x, y and z" << endl;
            cin >> x1 >> y1 >> z1; 
            GeomVector a(x1, y1, z1);
            vector<GeomVector> vectors;
            vectors.push_back(a);
            GeomVector result = a.getNormalized();
            vectors.push_back(result);
            Writer writer;
            string filepath = "output/vector.txt";
            writer.write(filepath, vectors);
        }
        break;

        case 4:
        {
            int newLength;
            cout << "Enter value for x, y and z" << endl;
            cin >> x1 >> y1 >> z1; 
            GeomVector a(x1, y1, z1);
            vector<GeomVector> vectors;
            vectors.push_back(a);

            cout << "Enter new length " << endl;
            cin >> newLength;
            GeomVector result = a.setVectorLength(newLength);

            vectors.push_back(result);
            Writer writer;
            string filepath = "output/vector.txt";
            writer.write(filepath, vectors);
        }

        case 5:
        {
            int scalarValue;
            cout << "Enter x, y and z value for vector1" << endl;
            cin >> x1 >> y1 >> z1; 
            GeomVector a(x1, y1, z1);

            cout << "Enter integer value" << endl;
            cin >> scalarValue;

            GeomVector result = a.addScalar(scalarValue);
            vector<GeomVector> vectors;
            vectors.push_back(result);
            Writer writer;
            string filepath = "output/vector.txt";
            writer.write(filepath, vectors);
        }
        break;

        case 6:
        {
            int scalarValue;
            cout << "Enter x, y and z value for vector1" << endl;
            cin >> x1 >> y1 >> z1; 
            GeomVector a(x1, y1, z1);

            cout << "Enter integer value" << endl;
            cin >> scalarValue;

            GeomVector result = a.subtractScalar(scalarValue);
            vector<GeomVector> vectors;
            vectors.push_back(a);
            vectors.push_back(result);
            Writer writer;
            string filepath = "output/vector.txt";
            writer.write(filepath, vectors);
        }
        break;
        case 7:
        {
            int scalarValue;
            cout << "Enter x, y and z value for vector1" << endl;
            cin >> x1 >> y1 >> z1; 
            GeomVector a(x1, y1, z1);

            cout << "Enter integer value" << endl;
            cin >> scalarValue;

            GeomVector result = a.multiplyScalar(scalarValue);
            vector<GeomVector> vectors;
            vectors.push_back(a);
            vectors.push_back(result);
            Writer writer;
            string filepath = "output/vector.txt";
            writer.write(filepath, vectors);
        }
        break;

        case 8:
        {
            int scalarValue;
            cout << "Enter x, y and z value for vector1" << endl;
            cin >> x1 >> y1 >> z1; 
            GeomVector a(x1, y1, z1);

            cout << "Enter integer value" << endl;
            cin >> scalarValue;

            GeomVector result = a.divideScalar(scalarValue);
            vector<GeomVector> vectors;
            vectors.push_back(a);
            vectors.push_back(result);
            Writer writer;
            string filepath = "output/vector.txt";
            writer.write(filepath, vectors);
        }
        break;

        case 9:
        {
            cout << "Enter x, y and z value for vector1" << endl;
            cin >> x1 >> y1 >> z1; 
            GeomVector a(x1, y1, z1);

            cout << "Enter x, y and z value for vector1" << endl;
            cin >> x2 >> y2 >> z2; 
            GeomVector b(x2, y2, z2);

            GeomVector result = a + b;
            vector<GeomVector> vectors;
            vectors.push_back(a);
            vectors.push_back(b);
            vectors.push_back(result);
            Writer writer;
            string filepath = "output/vector.txt";
            writer.write(filepath, vectors);
        }
        break;

        case 10:
        {
            cout << "Enter x, y and z value for vector1" << endl;
            cin >> x1 >> y1 >> z1; 
            GeomVector a(x1, y1, z1);

            cout << "Enter x, y and z value for vector1" << endl;
            cin >> x2 >> y2 >> z2; 
            GeomVector b(x2, y2, z2);

            double result = a.getDotProduct(b);
            vector<GeomVector> vectors;
            vectors.push_back(a);
            vectors.push_back(b);
            cout << "dot product is " << result << endl;
            Writer writer;
            string filepath = "output/vector.txt";
            writer.write(filepath, vectors);
        }
        break;

        case 11:
        {
            cout << "Enter x, y and z value for vector1" << endl;
            cin >> x1 >> y1 >> z1; 
            GeomVector a(x1, y1, z1);

            cout << "Enter x, y and z value for vector1" << endl;
            cin >> x2 >> y2 >> z2; 
            GeomVector b(x2, y2, z2);

            GeomVector result = a.getCrossProduct(b);
            vector<GeomVector> vectors;
            vectors.push_back(a);
            vectors.push_back(b);
            vectors.push_back(result);
            Writer writer;
            string filepath = "output/vector.txt";
            writer.write(filepath, vectors);
        }
        break;

        case 12:
        {
            cout << "Enter x, y and z value for vector1" << endl;
            cin >> x1 >> y1 >> z1; 
            GeomVector a(x1, y1, z1);
            a.directionCosines();
            vector<GeomVector> vectors;
            vectors.push_back(a);
        }
        break;

        case 13:
        {
            cout << "Enter x, y and z value for vector1" << endl;
            cin >> x1 >> y1 >> z1; 
            GeomVector a(x1, y1, z1);

            double s, b, c, d, e, f, g, h, i;
            cout << "Enter the elements of the 3 x 3 matrix: ";
            cin >> s >> b >> c >> d >> e >> f >> g >> h >> i;
            Matrix matrix(s, b, c, d, e, f, g, h, i);

            GeomVector result = a.multiplyMatrix(matrix);
            vector<GeomVector> vectors;
            vectors.push_back(a);
            vectors.push_back(result);
            Writer writer;
            string filepath = "output/vector.txt";
            writer.write(filepath, vectors);
        }
        break;

        case 14:
        {
            cout << "Enter x, y and z value for vector1" << endl;
            cin >> x1 >> y1 >> z1; 
            GeomVector a(x1, y1, z1);

            cout << "Enter x,y and z value for vector2" << endl;
            cin >> x2 >> y2 >> z2; 
            GeomVector b(x2, y2, z2);

            double result = a.getDistanceBetweenVectors(b);
            cout << "Distance between two vectors is " << result << endl;
        }
        break;

        case 15:
        {
            double x3, y3, z3; 
            cout << "Enter x, y and z value for vector1" << endl;
            cin >> x1 >> y1 >> z1; 
            GeomVector a(x1, y1, z1);

            cout << "Enter x,y and z value for normal" << endl;
            cin >> x2 >> y2 >> z2; 
            GeomVector normal(x2, y2, z2);

            cout << "Enter 3 coordinates for point" << endl;
            cin >> x3 >> y3 >> z3; 
            Point3D point(x3, y3, z3);

            Plane plane(normal, point);
            double result = a.getDistanceBetweenVectorAndPlane(plane);
            cout << "Distance between vector and plane is " << result << endl;
        }
        break;

        case 16:
        {

            cout << "Enter x, y and z value for vector1" << endl;
            cin >> x1 >> y1 >> z1; 
            GeomVector a(x1, y1, z1);

            cout << "Enter x,y and z value for normal" << endl;
            cin >> x2 >> y2 >> z2; 
            GeomVector b(x2, y2, z2);

            double result = a.getAngleBetweenVectors(b);
            cout << "Angle between two vectors is " << result << endl;
        }
        break;

        case 17:
        {
            double x3, y3, z3; 
            cout << "Enter x, y and z value for vector1" << endl;
            cin >> x1 >> y1 >> z1; 
            GeomVector a(x1, y1, z1);

            cout << "Enter x,y and z value for normal" << endl;
            cin >> x2 >> y2 >> z2; 
            GeomVector normal(x2, y2, z2);

            cout << "Enter 3 coordinates for point" << endl;
            cin >> x3 >> y3 >> z3; 
            Point3D point(x3, y3, z3);

            Plane plane(normal, point);
            double result = a.getAngleBetweenVectorAndPlane(plane);
            cout << "angle between vector and plane is " << result << endl;
        }
        break;

        case 18:
        {
            cout << "Enter x, y and z value for vector1" << endl;
            cin >> x1 >> y1 >> z1; 
            GeomVector a(x1, y1, z1);

            cout << "Enter x,y and z value for normal" << endl;
            cin >> x2 >> y2 >> z2; 
            GeomVector b(x2, y2, z2);

            GeomVector result = a.projectionOnVector(b);
            vector<GeomVector> vectors;
            vectors.push_back(a);
            vectors.push_back(b);
            vectors.push_back(result);
            Writer writer;
            string filepath = "output/vector.txt";
            writer.write(filepath, vectors);
        }
        break;

        case 19:
        {
            double x3, y3, z3; 
            cout << "Enter x, y and z value for vector1" << endl;
            cin >> x1 >> y1 >> z1; 
            GeomVector a(x1, y1, z1);

            cout << "Enter x,y and z value for normal" << endl;
            cin >> x2 >> y2 >> z2; 
            GeomVector normal(x2, y2, z2);

            GeomVector result = a.projectVectorOnPlane(a, normal);
            vector<GeomVector> vectors;
            vectors.push_back(a);
            vectors.push_back(normal);
            vectors.push_back(result);
            Writer writer;
            string filepath = "output/vector.txt";
            writer.write(filepath, vectors);
        }
        case 21: // Exit case
            exitLoop = true;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}
