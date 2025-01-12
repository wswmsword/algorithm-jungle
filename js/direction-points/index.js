
function main(...ps) {

  const sortedX = [...ps];
  sortedX.sort((p1, p2) => p1[0] - p2[0]);
  const sortedY = [...ps];
  sortedY.sort((p1, p2) => p1[1] - p2[1]);
  const dirMap = new Map();

  ps.forEach(p => {

    const [x, y] = p;
    const pOrderY = sortedY.findIndex(e => e === p);
    const pOrderX = sortedX.findIndex(e => e === p);

    // 获取 p 之上一点
    const upPs = sortedY.slice(pOrderY + 1).filter(([x2, y2]) => Math.abs(x2 - x) < Math.abs(y2 - y));
    let minUpPs = [];
    let minUpLen = Infinity;
    upPs.forEach(p2 => {
      const [x2, y2] = p2;
      const len = getDistance(x, y, x2, y2);
      if (minUpLen > len) {
        minUpLen = len;
        minUpPs = [p2];
      } else if (minUpLen === len)
        minUpPs.push(p2);
    });
    let minOffsetUp = Infinity;
    let minUpP = null;
    minUpPs.forEach(p2 => {
      const [x2] = p2;
      const offset = Math.abs(x - x2);
      if (offset < minOffsetUp) {
        minOffsetUp = offset;
        minUpP = p2;
      }
    });

    // 获取 p 之下一点
    const downPs = sortedY.slice(0, pOrderY).filter(([x2, y2]) => Math.abs(x2 - x) < Math.abs(y2 - y));
    let minDownPs = [];
    let minDownLen = Infinity;
    downPs.forEach(p2 => {
      const [x2, y2] = p2;
      const len = getDistance(x, y, x2, y2);
      if (minDownLen > len) {
        minDownLen = len;
        minDownPs = [p2];
      } else if (minDownLen === len)
        minDownPs.push(p2);
    });
    let minOffsetDown = Infinity;
    let minDownP = null;
    minDownPs.forEach(p2 => {
      const [x2] = p2;
      const offset = Math.abs(x - x2);
      if (offset < minOffsetDown) {
        minOffsetDown = offset;
        minDownP = p2;
      }
    });

    // 获取 p 之左一点
    const leftPs = sortedX.slice(0, pOrderX).filter(([x2, y2]) => Math.abs(y2 - y) <= Math.abs(x2 - x));
    let minLeftPs = [];
    let minLeftLen = Infinity;
    leftPs.forEach(p2 => {
      const [x2, y2] = p2;
      const len = getDistance(x, y, x2, y2);
      if (minLeftLen > len) {
        minLeftLen = len;
        minLeftPs = [p2];
      } else if (minLeftLen === len)
        minLeftPs.push(p2);
    });
    let minOffsetLeft = Infinity;
    let minLeftP = null;
    minLeftPs.forEach(p2 => {
      const [, y2] = p2;
      const offset = Math.abs(y - y2);
      if (offset < minOffsetLeft) {
        minOffsetLeft = offset;
        minLeftP = p2;
      }
    });

    // 获取 p 之右一点
    const rightPs = sortedX.slice(pOrderX + 1).filter(([x2, y2]) => Math.abs(y2 - y) <= Math.abs(x2 - x));
    let minRightPs = [];
    let minRightLen = Infinity;
    rightPs.forEach(p2 => {
      const [x2, y2] = p2;
      const len = getDistance(x, y, x2, y2);
      if (minRightLen > len) {
        minRightLen = len;
        minRightPs = [p2];
      } else if (minRightLen === len)
        minRightPs.push(p2);
    });
    let minOffsetRight = Infinity;
    let minRightP = null;
    minRightPs.forEach(p2 => {
      const [, y2] = p2;
      const offset = Math.abs(y - y2);
      if (offset < minOffsetRight) {
        minOffsetRight = offset;
        minRightP = p2;
      }
    });

    dirMap.set(p, {
      up: minUpP,
      down: minDownP,
      left: minLeftP,
      right: minRightP,
    })
  });

  return dirMap;
}

main([8, 6], [12, 1], [12, 7], [1, 1], [2, 3], [3, 5], [1, 7]);

function getDistance(x1, y1, x2, y2) {
  const dx = x2 - x1;
  const dy = y2 - y1;
  return dx * dx + dy * dy; // without sqrt
}