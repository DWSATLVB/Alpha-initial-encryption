# Alpha-initial-encryption
The Alpha Initial Encryption algorithm works by first randomly assigning unique numeric positions to all characters, including uppercase and lowercase letters (A-Z, a-z), digits (0-9), and special characters (e.g., punctuation marks and symbols). This mapping is randomized each time the program runs, making the encryption dynamic and difficult to predict. To encrypt a message, the algorithm combines the mapped numeric values of each character in the plaintext with the corresponding characters from a user-provided key, using a Vigenère-like method. If the resulting value exceeds the total number of unique positions, it wraps around to stay within the valid range. The program then outputs the encrypted message along with the character-to-number mapping used during the encryption process, ensuring that the same mapping can be applied for decryption. This approach offers both security and flexibility, as each encryption is unique due to the randomized character mapping.

# Example: 
#### Encrypting Algorithm
![Image](https://github.com/user-attachments/assets/8dd239aa-7ffa-4b95-96c7-649a643ddba5)

(PLEASE, someone get me Clion 🙏) ;-;
