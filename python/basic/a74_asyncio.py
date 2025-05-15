#비동기 실습

import asyncio
import time

async def hello():
    print("hello world.")
    await asyncio.sleep(5.0)
    # time.sleep(5)
    
def hello2():
    print("hello world2")
    time.sleep(5)
    
async def main():
    # for i in range(3):
    #     await hello()
    
    # hello2()
    
    # tasks = [hello(), hello(), hello()]
    # await asyncio.gather(*tasks)
    await hello()
    
    # tasks = [asyncio.create_task(hello()) for i in range(3)]
    # for task in tasks:
    #     await task
    
    t1 = asyncio.create_task(hello())
    t2 = asyncio.create_task(hello())
    t3 = asyncio.create_task(hello())
      
    await t1
    await t2
    await t3
      
    for i in range(3):
        await hello()
    
    print("main func end")
    
if __name__ == "__main__":
    asyncio.run(main())