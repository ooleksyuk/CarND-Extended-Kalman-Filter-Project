#pragma once

#include "measurement_package.h"
#include "kalman_filter.h"
#include "tools.h"
#include <eigen3/Eigen/Dense>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using Eigen::MatrixXd;
using Eigen::VectorXd;
using std::vector;
using namespace std;

class FusionEKF {
public:
  /**
  * Constructor.
  */
  FusionEKF();

  /**
  * Destructor.
  */
  virtual ~FusionEKF();

  /**
  * Run the whole flow of the Kalman Filter from here.
  */
  void ProcessMeasurement(const MeasurementPackage &measurement_pack);

  /**
  * Kalman Filter update and prediction math lives in here.
  */
  KalmanFilter ekf_;

private:
  // check whether the tracking toolbox was initialized or not (first measurement)
  bool is_initialized_;

  // previous timestamp
  long long previous_timestamp_;
  int noise_ax;
  int noise_ay;

  // tool object used to compute Jacobian and RMSE
  Tools tools;
  Eigen::MatrixXd R_laser_;
  Eigen::MatrixXd R_radar_;
  Eigen::MatrixXd H_laser_;
  Eigen::MatrixXd Hj_;
};