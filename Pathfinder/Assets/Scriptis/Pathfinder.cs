using System.Collections.Generic;
using System.Linq;
using UnityEngine;

public class Pathfinder : MonoBehaviour
{
    public GameObject Tile;

    public int Width = 20;
    public int Height = 20;
    public float Spacing = 1.1f;

    public Vector2Int StartPos = new Vector2Int(1, 2);

    public Vector2Int TargetPos = new Vector2Int(19, 17);

    public List<Vector2Int> ObstaclePos = new List<Vector2Int>();

    // Unvisited list of slabs
    private List<CustomSlab> unvisitedSlabs = new List<CustomSlab>();

    // Visited list of slabs
    private List<CustomSlab> visitedSlabs = new List<CustomSlab>();

    private bool bStart = true;

    // Start is called before the first frame update
    void Start()
    {
        for (int y = 0; y < Height; y++)
        {
            for (int x = 0; x < Width; x++)
            {
                GameObject obj = Instantiate(Tile, new Vector3(x * Spacing, y * Spacing, 0), Tile.transform.rotation);
                CustomSlab slab = obj.GetComponent<CustomSlab>();
                slab.SetCost(int.MaxValue);
                slab.Pos = new Vector2Int(x + 1, y + 1);

                foreach (Vector2Int pos in ObstaclePos)
                {
                    if (slab.Pos == pos)
                    {
                        slab.IsWalkable = false;
                        break;
                    }
                }

                if (slab.Pos == StartPos)
                {
                    slab.SetCost(0);
                }

                if (slab.IsWalkable)
                {
                    unvisitedSlabs.Add(slab);
                }
            }
        }

        Camera.main.transform.position = new Vector3(Width / 2 * Spacing, Height / 2 * Spacing, (Height < Width) ? -Width * Spacing : -Height * Spacing);
    }

    // Update is called once per frame
    void Update()
    {
        if (bStart)
        {
            // Set colors and costs
            foreach (CustomSlab slab in unvisitedSlabs)
            {
                if (slab.Pos == StartPos)
                {
                    slab.SetColor(Color.green);
                }
                else if (slab.Pos == TargetPos)
                {
                    slab.SetColor(Color.red);
                }
            }
            Dijkstra();
            TraceRoute();
            bStart = false;
        }
    }

    private void Dijkstra()
    {
        // While unvisited list is not empty
        // -Select the tile with the lowest cost
        // -Remove it from the list and set it as current tile
        // -Go through its surrounding slabs (Ignore the visited ones)
        // -Add the current tile to the visited list

        while (unvisitedSlabs.Count > 0)
        {
            int minCost = unvisitedSlabs.Min(slab => slab.GetCost());
            CustomSlab currentTile = unvisitedSlabs.Find(slab => slab.GetCost() == minCost);
            //CustomSlab currentTile = unvisitedSlabs.Find(s => s.Pos == StartPos);
            unvisitedSlabs.Remove(currentTile);

            for (int x = currentTile.Pos.x - 1; x <= currentTile.Pos.x + 1; x++)
            {
                for (int y = currentTile.Pos.y - 1; y <= currentTile.Pos.y + 1; y++)
                {
                    if (x < 1 || x > Width || y < 1 || y > Height)
                    {
                        continue;
                    }

                    Vector2Int neighborPos = new Vector2Int(x, y);
                    if (neighborPos == currentTile.Pos)
                    {
                        continue;
                    }

                    CustomSlab neighbor = unvisitedSlabs.Find(tile => tile.Pos == neighborPos);
                    if (neighbor == null)
                    {
                        continue;
                    }

                    Vector2Int delta = neighborPos - currentTile.Pos;
                    delta.x = Mathf.Abs(delta.x);
                    delta.y = Mathf.Abs(delta.y);
                    int moveCost = (delta.x + delta.y == 1) ? 10 : 14;

                    int costToNeighbor = currentTile.GetCost() + moveCost;

                    if (costToNeighbor < neighbor.GetCost())
                    {
                        neighbor.SetCost(costToNeighbor);
                        neighbor.Origin = currentTile.Pos;
                    }
                }
            }

            visitedSlabs.Add(currentTile);
        }
    }

    private void TraceRoute()
    {
        CustomSlab slab = visitedSlabs.Find(s => s.Pos == TargetPos);
        if (slab == null)
        {
            return;
        }

        while (slab.Pos != StartPos)
        {
            slab = visitedSlabs.Find(s => s.Pos == slab.Origin);
            if (slab.Pos == StartPos)
            {
                break;
            }
            slab.SetColor(Color.blue);
        }
    }
}
