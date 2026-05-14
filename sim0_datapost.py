import matplotlib.pyplot as plt 
import pandas as pd

data = pd.read_csv('sim0_trajectory.csv')

time = data['Time(s)']
x_pos = data['X(m)']
y_pos = data['Y(m)']

plt.figure()

plt.plot(x_pos,y_pos, label= "Projectile Trajectory", color="red")

plt.title('C++ Kinematics Simulation')
plt.xlabel('Horizontal Distance (m)')
plt.ylabel('Vertical Height (m)')
plt.grid(True)
plt.legend()

plt.show()
