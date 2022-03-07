from Crypto.Cipher import AES

def decrypt(ctext: str, key: str) -> str:
    ctext, key = bytes.fromhex(ctext), bytes.fromhex(key)
    ptext = AES.new(key, AES.MODE_ECB).decrypt(ctext)
    return ptext.hex().upper()

def encrypt(ptext: str, key: str) -> str:
    ptext, key = bytes.fromhex(ptext), bytes.fromhex(key)
    ctext = AES.new(key, AES.MODE_ECB).encrypt(ptext)
    return ctext.hex().upper()

print(decrypt(
    decrypt("6323B4A5BC16C479ED6D94F5B58FF0C2", "70000000000000000000000000000000"),
        "A0000000000000000000000000000000"
)) # 00112233445566778899AABBCCDDEEFF

print(encrypt(
    encrypt("00112233445566778899AABBCCDDEEFF", "A0000000000000000000000000000000"),
        "70000000000000000000000000000000"
)) # 6323B4A5BC16C479ED6D94F5B58FF0C2