import numpy as np

def read_config(filename, skip=2):
    """Reading an vicsek configuration from a file handle"""
    with open(filename) as file_handle:
        # skip the first two lines
        for i in range(skip): 
            next(file_handle)

        data = np.loadtxt(file_handle)
        conf = {}

        conf["id"] = data[:,0]
        conf["x"] = data[:,1]
        conf["y"] = data[:,2]
        conf["theta"] = data[:,3]
        conf["vx"] = np.cos(conf["theta"])
        conf["vy"] = np.sin(conf["theta"])  
        return conf


def plot(conf,ax):
    ax.figure(figsize=(5,5))
    qv = ax.quiver(conf["x"], conf["y"], conf["vx"], conf["vy"], conf["theta"], scale=1, scale_units='xy', cmap='hsv')
    plt.axis('equal')
    return qv