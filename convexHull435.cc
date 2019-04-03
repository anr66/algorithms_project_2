// You need to complete this program for your second project.

// Standard libraries
#include <string>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <sstream>

#include "graham_scan.h"
#include "jarvis_march.h"
#include "quick_hull.h"



int main(int argc, char *argv[])
{
	//Second project starts here
	if (argc < 3)
	{
		std::cout << "wrong format! should be \"a.exe algType dataFile\"";
	}

	else
	{
		std::string algType = argv[1];
		std::string dataFilename = argv[2];
		std::string outputFilename = "";


		// Read data from file and format it into a vector of points
		std::vector<Point> data;

		std::ifstream input_file;
		input_file.open(dataFilename.c_str());
		while (input_file.fail())
		{
			std::cout << "Error opening file, try again" << "\n";
			std::cin >> dataFilename;
			input_file.open(dataFilename.c_str());
		}

		std::string line;
		while(getline(input_file, line))
		{
			if(line.length() > 0)
			{
				Point point;
				std::istringstream iss(line);
				std::string s;
				iss >> s;
				point.x = std::stoi(s);
				iss >> s;
				point.y = std::stoi(s);
				data.push_back(point);
			}
		}

		std::vector<Point> result;

		//read your data points from dataFile (see class example for the format)

		clock_t start, stop;
		start = clock();

		if (algType[0]=='G')
		{
			//call your Graham Scan algorithm to solve the problem
			result = convexHullGraham(data, data.size());
			outputFilename = "hull_G.txt";
		}

		else if (algType[0]=='J')
		{
			//call your Javis March algorithm to solve the problem
			result = convexHullJarvis(data, data.size());
			outputFilename = "hull_J.txt";
		}

		else if (algType[0]=='Q')
		{ //default
			int i = 0;
			iPair data_pair[data.size()];

			vector<Point>::iterator vector_iter;
			for(vector_iter = data.begin(); vector_iter != data.end(); ++vector_iter)
			{
				iPair p;
				p.first = (*vector_iter).x;
				p.second = (*vector_iter).y;
				//(*vector_iter).x = p.first;
				//(*vector_iter).y = p.second;
				data_pair[i] = p;
				i++;
			}
			//call your Quickhull algorithm to solve the problem
			start = clock();
			outputFilename = "hull_Q.txt";
			result = convexHullQuick(data_pair, data.size());
		}

		stop = clock();

		std::cout << "Runtime for " << dataFilename << ": " << 1000 * (double(stop-start)/double(CLOCKS_PER_SEC)) << " milliseconds\n";

		// write the result to the output file
		std::ofstream output_file;
		output_file.open(outputFilename);

		std::size_t i;
		std::size_t size = result.size();
		for (i = 0; i < size; ++i)
		{
			Point point = result[i];
			output_file << point.x << " " << point.y;
			if (i != size - 1)
			{
				output_file << "\n";
			}
		}

		output_file.close();

		//write your convex hull to the outputFile (see class example for the format)
		//you should be able to visulize your convex hull using the "ConvexHull_GUI" program.

		return 0;
	}
}
