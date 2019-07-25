import webview


webview.create_window('Neural Paint', 'http://localhost:8100')

import asyncio
import websockets

async def hello(websocket, path):
    name = await websocket.recv()
    print("Msg received from the client: '{}'".format(name))
    msg = "Hello {}!".format(name)
    print("Msg sending to the client: '{}'".format(msg))
    await websocket.send(msg)
    print("Msg sent")


headers = websockets.http.Headers()
headers["Access-Control-Allow-Origin"] = "*"
headers["Access-Control-Allow-Headers"] = "origin, x-requested-with, content-type"
headers["Access-Control-Allow-Methods"] = "PUT, GET, POST, DELETE, OPTIONS"

start_server = websockets.serve(hello, 'localhost', 8100, extra_headers=headers)

import webview
import traceback

try:
webview.create_window('Neural Paint', 'http://localhost:8100')
except:
	print(traceback.format_exc()[:-1])

asyncio.get_event_loop().run_until_complete(start_server)
asyncio.get_event_loop().run_forever(