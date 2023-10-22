import torch
# print(torch.cuda.device_count())
# print(torch.cuda.current_device())

print('Checking for GPU...')
print(f'{torch.cuda.is_available()}')

# import tensorflow as tf
# print("Num GPUs Available: ", len(tf.config.list_physical_devices('GPU')))