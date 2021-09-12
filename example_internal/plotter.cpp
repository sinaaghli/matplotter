#include <cmath>

#include "matplotter/matplotter.h"

int main(int argc, char *argv[]) {
  // start a plot
  matplotter::PlotStart("this is a simple plot");

  // Plot a test sample
  matplotter::PlotTest();
  // show the sample plot, user needs to close the plot to continue
  matplotter::PlotShow();

  std::vector<double> data1d;
  for (int ii = 0; ii < 100; ii++) {
    data1d.push_back(ii);
  }
  // start a plot
  matplotter::PlotStart("this is a 1D plot");
  // plot one dimentional data in red
  matplotter::PlotY(data1d, "r", "1D plot");
  matplotter::PlotShow();

  std::vector<double> datax;
  std::vector<double> datay;
  for (int ii = 0; ii < 100; ii++) {
    datay.push_back(std::sin(0.1 * ii));
    datax.push_back(0.1 * ii);
  }
  // start a plot
  matplotter::PlotStart("this is a 2D plot");
  // plot two dimentional data
  matplotter::PlotXY(datax, datay, "b--", "2d plot");
  matplotter::PlotShow();

  return 0;
}
