#ifndef MATPLOTTER_H__
#define MATPLOTTER_H__

#include <chrono>
#include <iostream>
#include <thread>

#include "matplotlibcpp.h"

// error print formatting
#define ERROREXIT(X)                                                           \
  std::cerr << "Error in file:" << __FILE__ << " Line:" << __LINE__ << " "     \
            << X << std::endl;                                                 \
  std::exit(EXIT_FAILURE)
#define ERROR(X)                                                               \
  std::cerr << "Error in file:" << __FILE__ << " Line:" << __LINE__ << " "     \
            << X << std::endl

namespace matplotter {

typedef std::chrono::high_resolution_clock::time_point Timestamp;

inline void Delay_ms(unsigned int delay_time) {
  std::this_thread::sleep_for(std::chrono::milliseconds(delay_time));
}

inline void Delay_us(unsigned int delay_time) {
  std::this_thread::sleep_for(std::chrono::microseconds(delay_time));
}

inline Timestamp Tick() { return std::chrono::high_resolution_clock::now(); }

inline double Tock_ms(Timestamp tick_time) {
  Timestamp tock_time = std::chrono::high_resolution_clock::now();
  return std::chrono::duration_cast<std::chrono::milliseconds>(tock_time -
                                                               tick_time)
      .count();
}

inline double Tock_us(Timestamp tick_time) {
  Timestamp tock_time = std::chrono::high_resolution_clock::now();
  return std::chrono::duration_cast<std::chrono::microseconds>(tock_time -
                                                               tick_time)
      .count();
}

inline double Tock_ns(Timestamp tick_time) {
  Timestamp tock_time = std::chrono::high_resolution_clock::now();
  return std::chrono::duration_cast<std::chrono::nanoseconds>(tock_time -
                                                              tick_time)
      .count();
}

inline double TickTock_ms(Timestamp tick_time, Timestamp tock_time) {
  return std::chrono::duration_cast<std::chrono::milliseconds>(tock_time -
                                                               tick_time)
      .count();
}

inline double TickTock_us(Timestamp tick_time, Timestamp tock_time) {
  return std::chrono::duration_cast<std::chrono::microseconds>(tock_time -
                                                               tick_time)
      .count();
}

inline double TickTock_s(Timestamp tick_time, Timestamp tock_time) {
  return std::chrono::duration_cast<std::chrono::seconds>(tock_time - tick_time)
      .count();
}

inline void PlotY(std::vector<double> &y_axis, std::string style = "r-",
                  std::string ylabel = "") {

  // Plot line from given x and y data. Color is selected automatically.
  if (ylabel.empty()) {
    matplotlibcpp::plot(y_axis, style);
  } else {
    // Plot a line whose name will show upin the legend.
    matplotlibcpp::named_plot(ylabel, y_axis, style);
  }
}

inline void PlotXY(std::vector<double> &x_axis, std::vector<double> &y_axis,
                   std::string style = "r-", std::string ylabel = "") {

  // Plot line from given x and y data. Color is selected automatically.
  if (ylabel.empty()) {
    matplotlibcpp::plot(x_axis, y_axis, style);
  } else {
    // Plot a line whose name will show upin the legend.
    matplotlibcpp::named_plot(ylabel, x_axis, y_axis, style);
  }
}

inline void PlotStart(std::string title) {

  // Set the size of output image to 1200x780 pixels
  matplotlibcpp::figure_size(1200, 780);
  // Add graph title
  matplotlibcpp::title(title);
}

inline void PlotShow() {

  // Enable legend and show
  matplotlibcpp::legend();
  matplotlibcpp::show();
}

inline void PlotSave(std::string filename) {

  // Save the image (file format is determined by the extension) ex.
  // "./basic.png"
  matplotlibcpp::save(filename);
}

inline void PlotTest() {

  // Prepare data.
  int n = 5000;
  std::vector<double> x(n), y(n), z(n), w(n, 2);
  for (int i = 0; i < n; ++i) {
    x.at(i) = i * i;
    y.at(i) = sin(2 * M_PI * i / 360.0);
    z.at(i) = log(i);
  }

  // Set the size of output image to 1200x780 pixels
  // matplotlibcpp::figure_size(1200, 780);
  // Plot line from given x and y data. Color is selected automatically.
  matplotlibcpp::plot(x, y);
  // Plot a red dashed line from given x and y data.
  matplotlibcpp::plot(x, w, "r--");
  // Plot a line whose name will show up as "log(x)" in the legend.
  matplotlibcpp::named_plot("log(x)", x, z);
  // Set x-axis to interval [0,1000000]
  matplotlibcpp::xlim(0, 1000 * 1000);
}

} // namespace matplotter
#endif // MATPLOTTER_H__
