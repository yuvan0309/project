import numpy as np
import cv2

def erode(image, kernel):
    h, w = image.shape
    kh, kw = kernel.shape
    pad_h, pad_w = kh // 2, kw // 2
    padded_img = np.pad(image, ((pad_h, pad_h), (pad_w, pad_w)), mode='constant')
    result = np.zeros_like(image)

    for i in range(h):
        for j in range(w):
            region = padded_img[i:i+kh, j:j+kw]
            result[i, j] = np.min(region * kernel)

    return result

# Load image
image = cv2.imread('taj.jpg', cv2.IMREAD_GRAYSCALE)
if image is None:
    raise ValueError("Image not found! Check the file path.")

# Define kernel
kernel = np.ones((3, 3), dtype=np.uint8)

# Apply erosion
eroded_image = erode(image, kernel)

# Save the result
cv2.imwrite('eroded.jpg', eroded_image)
