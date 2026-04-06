# Configuração do Ambiente e Execução

### 1. Criação do Ambiente Virtual
```bash
python -m venv .venv
```

### 2. Ativação do Ambiente
* **Linux/macOS:**
  ```bash
  source .venv/bin/activate
  ```
* **Windows:**
  ```powershell
  .\.venv\Scripts\activate
  ```

### 3. Instalação das Dependências
```bash
pip install --upgrade pip
pip install -r requirements.txt
```

### 4. Registro do Kernel (Caso execute fora do VSCode)
```bash
python -m ipykernel install --user --name=nome_do_projeto --display-name "Python 3 (Lista 01)"
```

### 5. Execução (Caso execute fora do VSCode)
```bash
jupyter lab
```