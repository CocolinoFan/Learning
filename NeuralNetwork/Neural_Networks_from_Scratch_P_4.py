import numpy as np

inputs = [[1, 2, 3, 2.5],
          [2.0, 5.0, -1.0, 2.0],
          [-1.5, 2.7, 3.3, -0.8]]

weights = [[0.2, 0.8, -0.5, 1.0],
          [0.5, -0.91, 0.26, -0.5],
	      [-0.26, -0.27, 0.17, 0.87]] 

biases = [2, 3, 0.5]


weights1 = [[0.1, -0.14, 0.5],
          [-0.5, 0.12, -0.33],
          [-0.446, 0.73, -0.13]]

biases1 = [-1, 2, -0.5]


layer1_output = np.dot(inputs, np.array(weights).T) + biases

layer2_output = np.dot(layer1_output, np.array(weights1).T) + biases1

print(layer2_output)
