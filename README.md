# Code_Repo
A housing place for commonly used or referenced code

# Build System

bazel-6.5.0

Install instruction page:

```
https://bazel.build/install/ubuntu
```

Directions copied here:

1. Install gpg keys and archives

```
sudo apt install apt-transport-https curl gnupg -y
curl -fsSL https://bazel.build/bazel-release.pub.gpg | gpg --dearmor >bazel-archive-keyring.gpg
sudo mv bazel-archive-keyring.gpg /usr/share/keyrings
echo "deb [arch=amd64 signed-by=/usr/share/keyrings/bazel-archive-keyring.gpg] https://storage.googleapis.com/bazel-apt stable jdk1.8" | sudo tee /etc/apt/sources.list.d/bazel.list
```

2. Update and install bazel (this will download latest version of bazel)

```
sudo apt update && sudo apt install bazel
```

3. For specific bazel version:

```
sudo apt install bazel-6.5.0
```

4. Create symlink (optional):

```
ln -s /usr/bin/bazel-6.5.0 /usr/bin/bazel
```
