import os
from Crypto.Cipher import AES
import hashlib

class AESCipher(object):
    def __init__(self, key, iv):
        self.key = hashlib.sha256(key.encode()).digest()
        self.iv = hashlib.md5(iv.encode()).digest()

    def decrypt(self, enc):
        cipher = AES.new(self.key, AES.MODE_CBC, self.iv)
        dec = cipher.decrypt(enc)
        return dec

def Decoding(full_filename):
    HASH = '0ebdb7f9b238c2fd40f922099b7d65f24ffa3f084deccf0ea40f658e09b2a1ec'
    iv = 'enlqerhi'
    aes = AESCipher(HASH, iv)

    file_old = open(full_filename, 'rb')
    data = file_old.read()

    decrypt = aes.decrypt(data)

    file_new = open(full_filename[0:-9], 'wb')
    file_new.write(decrypt)

    file_old.close()
    file_new.close()

    os.remove(full_filename)


def Target(Extension):
    if Extension in ['.txt', '.accdb']:
        return True
    else:
        return False

def run(dirname):
    for (path, dir, files) in os.walk(dirname):
        for filename in files:
            full_filename = os.path.join(path, filename)
            Extension = os.path.splitext(filename)[-1]
            if Target(Extension) == False:
                Decoding(full_filename)

if __name__ == "__main__":
    target_local = "<Target_Path>"

    KEY_HASH = '0ebdb7f9b238c2fd40f922099b7d65f24ffa3f084deccf0ea40f658e09b2a1ec'
    TEMP_HASH = hashlib.sha256(KEY.encode()).hexdigest()

    if KEY_HASH == TEMP_HASH:
        run(target_local)
