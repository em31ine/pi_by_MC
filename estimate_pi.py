# Import python packages
import numpy as np
import time

N_list = [int(1e2), int(1e3), int(1e4), int(1e5), int(1e6), int(1e7), int(1e8)]     # list of all N values as described in teh assignment

# traverse through the list of sample sizes (N_list) and perform the following calcs
for N in N_list:
    start = time.time()         # start recording time for sample N

    in_circle_count = 0         # variable that will count the number of samples that land inside the circle   

    x = np.random.uniform(-1, 1, N)         # sample x-direction
    y = np.random.uniform(-1, 1, N)         # sample y-direction

    in_circle_count += np.sum(x*x + y*y <= 1)   # add to circle count for the number of x-y pairs of the sample that land in the circle

    ratio = in_circle_count / N         # calculate the ratio of the # of samples in the circle to total # samples

    pi_estimate = 4 * ratio         # estimate pi using the math outlined in problem statement
    true_pi = 3.14159265359         # true pi value as given in problem statement

    percent_error = (np.abs(pi_estimate - true_pi)/true_pi) * 100       # calculate the percent error (how off the estimated pi value is from "true pi")

    end = time.time()           # stop recording time for sample N

    print(f"N = {N:>9d} ; π ≈ {pi_estimate:.6f} ; % error = {percent_error:.4f}; time = {end-start:.4f} sec")           # print the same size, est. pi, error, and sim. length
