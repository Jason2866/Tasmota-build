FROM gitpod/workspace-python-3.13

RUN python -m pip install --break-system-packages uv

USER gitpod
