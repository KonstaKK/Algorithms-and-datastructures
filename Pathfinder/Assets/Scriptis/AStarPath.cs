using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;

public class AStarPath : MonoBehaviour
{
    public GameObject Tile;

    [Range(1, 100)]
    public int Width = 20, Height = 20;
    public float Spacing = 1.1f;

    public bool GetAll;

    public Vector2Int StartPos = new Vector2Int(1, 2);

    public Vector2Int TargetPos = new Vector2Int(19, 17);

    public List<Vector2Int> ObstaclePos = new List<Vector2Int>();

    // Unvisited list of slabs
    private List<AStarSlab> unvisitedSlabs = new List<AStarSlab>();

    // Visited list of slabs
    private List<AStarSlab> visitedSlabs = new List<AStarSlab>();

    private bool bStart = true;

    // Start is called before the first frame update
    void Start()
    {
        for (int y = 0; y < Height; y++)
        {
            for (int x = 0; x < Width; x++)
            {
                GameObject obj = Instantiate(Tile, new Vector3(x * Spacing, y * Spacing, 0), Tile.transform.rotation);
                AStarSlab slab = obj.GetComponent<AStarSlab>();
                slab.Pos = new Vector2Int(x + 1, y + 1);
                slab.ComputeHCost(TargetPos);
                slab.SetGCost(int.MaxValue);

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
                    slab.SetGCost(0);
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
            foreach (AStarSlab slab in unvisitedSlabs)
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
            //AStar();
            //TraceRoute();
            StartCoroutine(DoASTar());
            bStart = false;
        }
    }

    IEnumerator DoASTar()
    {
        while (unvisitedSlabs.Count > 0)
        {
            if (StepAStar().Pos == TargetPos && !GetAll)
            {
                break;
            }
            yield return new WaitForSeconds(Time.fixedDeltaTime);
        }
        TraceRoute(Color.gray);
    }

    private AStarSlab StepAStar()
    {
        int minCost = unvisitedSlabs.Min(slab => slab.GetFCost());
        AStarSlab currentTile = unvisitedSlabs.Find(slab => slab.GetFCost() == minCost);
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

                AStarSlab neighbor = unvisitedSlabs.Find(tile => tile.Pos == neighborPos);
                if (neighbor == null)
                {
                    continue;
                }

                if (neighbor.Pos != TargetPos)
                {
                    neighbor.SetColor(Color.magenta);
                }

                Vector2Int delta = neighborPos - currentTile.Pos;
                delta.x = Mathf.Abs(delta.x);
                delta.y = Mathf.Abs(delta.y);
                int moveCost = (delta.x + delta.y == 1) ? 10 : 14;

                int costToNeighbor = currentTile.GetGCost() + moveCost;

                if (costToNeighbor < neighbor.GetGCost())
                {
                    neighbor.SetGCost(costToNeighbor);
                    neighbor.Origin = currentTile.Pos;
                }
            }
        }

        if (currentTile.Pos != StartPos && currentTile.Pos != TargetPos)
        {
            currentTile.SetColor(Color.blue);
        }
        visitedSlabs.Add(currentTile);

        return currentTile;
    }

    private void AStar()
    {
        // While unvisited list is not empty
        // -Select the tile with the lowest cost
        // -Remove it from the list and set it as current tile
        // -Go through its surrounding slabs (Ignore the visited ones)
        // -Add the current tile to the visited list

        while (unvisitedSlabs.Count > 0)
        {
            int minCost = unvisitedSlabs.Min(slab => slab.GetFCost());
            AStarSlab currentTile = unvisitedSlabs.Find(slab => slab.GetFCost() == minCost);
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

                    AStarSlab neighbor = unvisitedSlabs.Find(tile => tile.Pos == neighborPos);
                    if (neighbor == null)
                    {
                        continue;
                    }

                    Vector2Int delta = neighborPos - currentTile.Pos;
                    delta.x = Mathf.Abs(delta.x);
                    delta.y = Mathf.Abs(delta.y);
                    int moveCost = (delta.x + delta.y == 1) ? 10 : 14;

                    int costToNeighbor = currentTile.GetFCost() + moveCost;

                    if (costToNeighbor < neighbor.GetFCost())
                    {
                        neighbor.SetGCost(costToNeighbor);
                        neighbor.Origin = currentTile.Pos;
                    }
                }
            }

            visitedSlabs.Add(currentTile);
        }
    }

    private void TraceRoute(Color color)
    {
        AStarSlab slab = visitedSlabs.Find(s => s.Pos == TargetPos);
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
            slab.SetColor(color);
        }
    }
}
