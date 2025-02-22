import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import matplotlib.animation as animation

GRID_SIZE = 50
DELTA_T = 0.01
DIFFUSION_COEFF = 0.1
INITIAL_PRESSURE = 1013.0
INITIAL_AQI = 50.0
TIME_STEPS = 100

pressure = np.full((GRID_SIZE, GRID_SIZE), INITIAL_PRESSURE)
aqi = np.full((GRID_SIZE, GRID_SIZE), INITIAL_AQI)

def update_grid():
    global pressure, aqi
    new_pressure = pressure.copy()
    new_aqi = aqi.copy()

    for i in range(1, GRID_SIZE - 1):
        for j in range(1, GRID_SIZE - 1):
            pressure_change = 0.25 * (
                pressure[i+1, j] + pressure[i-1, j] + pressure[i, j+1] + pressure[i, j-1] - 4 * pressure[i, j]
            )

            diffusion = DIFFUSION_COEFF * (
                aqi[i+1, j] + aqi[i-1, j] + aqi[i, j+1] + aqi[i, j-1] - 4 * aqi[i, j]
            )

            source_term = np.exp(-0.01 * pressure[i, j])

            new_pressure[i, j] += DELTA_T * pressure_change
            new_aqi[i, j] += DELTA_T * (diffusion + source_term)

    pressure[:] = new_pressure
    aqi[:] = new_aqi

def animate(frame):
    update_grid()
    ax1.clear()
    ax2.clear()

    sns.heatmap(pressure, ax=ax1, cmap="coolwarm", cbar=False)
    ax1.set_title(f"Pressure Distribution - Step {frame}")

    sns.heatmap(aqi, ax=ax2, cmap="YlOrRd", cbar=False)
    ax2.set_title(f"AQI Distribution - Step {frame}")

fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 5))

ani = animation.FuncAnimation(fig, animate, frames=TIME_STEPS, repeat=False)
plt.show()
