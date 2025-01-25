# Alpha-initial-encryption
This method encrypts a given input text (inp_main) using a key (key_main) through a custom mapping-based algorithm. Each character is assigned a unique numeric value: lowercase letters (a-z) are mapped to 1-26, uppercase letters (A-Z) to 27-52, and the space character ( ) to 53. The encryption adds the mapped values of corresponding characters from the input and key. If the result exceeds 53, it wraps around by subtracting 53 (like modular arithmetic). The resulting numbers are then mapped back to characters to form the encrypted text. 
# Note
The encryption method strongly resembles Vigenère Cipher and may not seem "original".

# Example: 
![Image](https://github.com/user-attachments/assets/ec71fedd-0d76-48f3-a9bb-3a3ae8f3c0f1)
(PLEASE, someone get me Clion 🙏) ;-;
